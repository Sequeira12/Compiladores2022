#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "semantics.h"




void verifica(no raiz){
    if(raiz){
        if(strcmp(raiz->s_type,"Program")==0) nova_classe(raiz->filho->valor);
        else if(strcmp(raiz->s_type, "MethodDecl")==0) {
            verifica_method_decl(raiz->filho);
        
        }else if(strcmp(raiz->s_type, "FieldDecl")==0) insere(raiz->filho,NULL,NULL,"Class");
        
        for(no f = raiz->filho; f!=NULL; f=f->irmao) verifica(f);
        

    }else{
        return;
    }
}

void verifica_method_decl(no node){
    char * tipo = verifica_type(node->filho->s_type);
    char * valor = (char*)strdup(node->filho->irmao->valor);
    char * parametros = verifica_method_params(node->filho->irmao->irmao);
    char ** array_de_parametros = verifica_array_method_params(node->filho->irmao->irmao);

    char *n = malloc(strlen(valor)+strlen(parametros)+1);
    if(n){
        n[0]='\0';
        strcat(n,valor);
        strcat(n,parametros);
    }
    if(verifica_repetidos(n)>0){
        insere(node->filho,parametros,NULL,"Class");

        novo_metodo(n,valor,array_de_parametros,tipo);
        no h = NULL;
        if(node->filho->irmao->irmao->filho){
            h = node->filho->irmao->irmao->filho;
            //printf("passouaqui\n");
        }
        //printf("-----\n");
        //to do: verificar se os parametros sao iguais
        for(h; h!= NULL; h=h->irmao) {
            //printf("%s\n", h->filho->irmao->valor);
            insere(h->filho,NULL, "param", n);
        }
    }else{
       printf("Line %s, Col %s: Symbol %s already defined\n", node->filho->irmao->line, node->filho->irmao->col,n);
    }
};

   /*         //printf("%s %s\n", h->filho->s_type,h->filho->irmao->valor);
            for(no aux = node->filho->irmao->irmao->filho;aux != NULL; aux=aux->irmao){
                if(strcmp(aux->filho->irmao->valor, h->filho->irmao->valor)==0){
                    printf("iguaissssss");
                    return;
                }else{
                    insere(h->filho,NULL, "param", n);
                }
            }*/



char * verifica_method_params(no node){
    if(node->filho){
        char parametros[200] = "(";

        for(no aux = node->filho; aux != NULL; aux = aux->irmao){
            if(strcmp(aux->filho->s_type, "StringArray") == 0) strcat(parametros,"String[]");
            else if(strcmp(aux->filho->s_type, "Double")==0)strcat(parametros, "double");
            else if(strcmp(aux->filho->s_type, "Bool")==0)strcat(parametros, "boolean");
            else if(strcmp(aux->filho->s_type, "Int") == 0)strcat(parametros, "int");
            if(aux->irmao) strcat(parametros,",");
        }
        strcat(parametros,")");
        return strdup(parametros);
    }else{
        return strdup("()");
    }
}


char ** check_calls_method_params(no raiz) {
    char ** params = (char**)malloc(50*sizeof(char*));
    no aux = NULL;
    int i = 1;
    if (raiz->filho->irmao) {
        aux = raiz->filho->irmao;
    }
    while (aux != NULL) {
        if (aux->id != NULL) {
            params[i] = strdup(&aux->id[3]);
            i++;
        }
        aux = aux->irmao;
    }
    char string[10];
    sprintf(string, "%d", i-1);
    params[0] = strdup(string);
    return params;
}



//retorna array com strings a indicar o tipo de parametros
char ** verifica_array_method_params(no node){
    char ** parametros = (char**)malloc(30*sizeof(char*));
    
    int x = 1;

    if(node->filho){

        for(no aux = node->filho; aux != NULL; aux = aux->irmao){
            if(strcmp(aux->filho->s_type, "StringArray") == 0)parametros[x]=strdup("String[]");
            else if(strcmp(aux->filho->s_type, "Double")==0)parametros[x]=strdup("double");
            else if(strcmp(aux->filho->s_type, "Bool")==0)parametros[x]=strdup("boolean");
            else if(strcmp(aux->filho->s_type, "Int") == 0)parametros[x]=strdup("int");
            x++;
        }
    }
    char numero[20];
    sprintf(numero,"%d", x-1);
    parametros[0]=strdup(numero);
    return parametros;
}

void verifica_method_body(char * tab, no node){
    if(node){
        if(strcmp(node->s_type,"VarDecl")==0)
        {insere(node->filho, NULL,NULL,tab);}

        if(strcmp(node->s_type,"Id")==0)node->id=procura_tabela(node,tab);  //verifica se ja existe na tabela de simbolos

        if(strcmp(node->s_type,"Declit")==0 || strcmp(node->s_type,"Length")==0 || strcmp(node->s_type,"ParseArgs")==0) node->id=(char*)strdup(" - int");

        if(strcmp(node->s_type, "Ne") == 0 || strcmp(node->s_type, "Eq") == 0 || strcmp(node->s_type, "Ge") == 0 || strcmp(node->s_type, "Gt") == 0 
        || strcmp(node->s_type, "Le") == 0 || strcmp(node->s_type, "Lt") == 0 || strcmp(node->s_type, "Not") == 0 || strcmp(node->s_type, "Or") == 0 
        || strcmp(node->s_type, "And") == 0 || strcmp(node->s_type, "BoolLit") == 0) node->id=(char*)strdup(" - boolean");

        if(strcmp(node->s_type,"StrLit")==0) node->id=(char*)strdup(" - String");

        if(strcmp(node->s_type,"RealLit")==0) node->id=(char*)strdup(" - double");
    

       /* if (strcmp(node->s_type,"Add")==0 || strcmp(node->s_type,"Sub")==0 
        || strcmp(node->s_type,"Div")==0 || strcmp(node->s_type,"Mul")==0 || strcmp(node->s_type,"Mod")==0)
        {
            printf("entrou9\n");
            if(strcmp(node->filho->id, node->filho->irmao->id) != 0) {
                printf("entrou7\n");
                node->id=(char*)strdup(" - double");
                printf("saiu7\n");
            }
            printf("naoéaqui\n");
            if(strcmp(node->filho->id, node->filho->irmao->id) == 0) {
                 printf("entrou8\n");
                node->id=(char*)strdup(node->filho->id);
                 printf("saiu8\n");
            }
             printf("saiu9\n");
        }*/
        no aux = node->filho;
        while (aux != NULL) {
            verifica_method_body(tab, aux);
            aux = aux->irmao;
        }
        if(strcmp(node->s_type, "Assign")==0 || strcmp(node->s_type, "Minus")==0 || strcmp(node->s_type, "Plus")==0)node->id=node->filho->id;

        if(strcmp(node->s_type,"Call")==0){
            char ** params = check_calls_method_params(node);
            tabela anota = check_call(node->filho->valor, params, 0);
            if (anota != NULL) {
                char * n_string;
                if ((n_string = malloc(strlen(" - ")+strlen(anota->tab->s_type)+1)) != NULL) {
                    n_string[0] = '\0';
                    strcat(n_string, " - ");
                    strcat(n_string, anota->tab->s_type);
                }
                node->id = n_string;
                int i = strlen(anota->c_nome);
                char * n_string2;
                if ((n_string2 = malloc(strlen(" - ")+strlen(&anota->nome[i])+1)) != NULL) {
                    n_string2[0] = '\0';
                    strcat(n_string2, " - ");
                    strcat(n_string2, &anota->nome[i]);
                }
                node->filho->id = n_string2;
            }
            else {
                char * n_string;
                if ((n_string = malloc(strlen(" - undef")+1)) != NULL) {
                    n_string[0] = '\0';
                    strcat(n_string, " - undef");
                }
                node->id = n_string;
                node->filho->id = n_string;
            }
        }

    }else{
        return;
    }
}


void check_ast(no raiz){
    if(raiz){
        if(strcmp(raiz->s_type, "MethodDecl")==0){
            char * params = verifica_method_params(raiz->filho->filho->irmao->irmao);
            char * valor = (char*)strdup(raiz->filho->filho->irmao->valor);

            char * n = malloc(strlen(params)+strlen(valor)+1);
            if(n){
                n[0]='\0';
                strcat(n, valor);
                strcat(n,params);
            }

            verifica_method_body(n,raiz->filho->irmao);

        }

    }else return;
    for(no aux = raiz->filho; aux!=NULL; aux=aux->irmao) check_ast(aux);
}