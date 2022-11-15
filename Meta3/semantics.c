#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "semantics.h"



void verifica(no raiz){
    if(raiz){
        if(strcmp(raiz->s_type,"Program")==0) nova_classe(raiz->filho->valor);
        else if(strcmp(raiz->s_type, "MethodDecl")==0) verifica_method_decl(raiz->filho);
        else if(strcmp(raiz->s_type, "FieldDecl")==0) insere(raiz->filho,NULL,NULL,"Class");
        
        for(no filho = raiz->filho; filho!=NULL; filho=filho->irmao) verifica(filho);
        

    }else{
        return;
    }
}

char* verifica_method_decl(no node){
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
    insere(node->filho,parametros,NULL,"Class");
    novo_metodo(n,valor,array_de_parametros,tipo);


    no h = NULL;
    if(node->filho->irmao->irmao->filho){
        h = node->filho->irmao->irmao->filho;
    }
    for(h; h!= NULL; h=h->irmao) insere(node->filho->irmao->irmao->filho,NULL, "param", n);

    return n;
};





char * verifica_method_params(no node){
    if(node->filho){
        char parametros[200] = "(";

        for(no aux = node->filho; aux != NULL; aux = aux->irmao){
            if(strcmp(aux->filho->s_type, "StringArray") == 0) strcat(parametros,"int");
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
        if(strcmp(node->s_type,"VarDecl")==0)insere(node->filho, NULL,NULL,tab);

        else if(strcmp(node->s_type,"Id")==0)node->id=procura_tabela(node,tab);  //verifica se ja existe na tabela de simbolos

        else if(strcmp(node->s_type,"Declit")==0 || strcmp(node->s_type,"Length")==0 || strcmp(node->s_type,"ParseArgs")==0) node->id=(char*)strdup(" - int");
        
        else if(strcmp(node->s_type, "Ne") == 0 || strcmp(node->s_type, "Eq") == 0 || strcmp(node->s_type, "Ge") == 0 || strcmp(node->s_type, "Gt") == 0 
        || strcmp(node->s_type, "Le") == 0 || strcmp(node->s_type, "Lt") == 0 || strcmp(node->s_type, "Not") == 0 || strcmp(node->s_type, "Or") == 0 
        || strcmp(node->s_type, "And") == 0 || strcmp(node->s_type, "BoolLit") == 0) node->id=(char*)strdup(" - boolean");
        
        else if(strcmp(node->s_type,"StrLit")==0) node->id=(char*)strdup(" - String");

        else if(strcmp(node->s_type,"RealLit")==0) node->id=(char*)strdup(" - double");



        //se filho e irmao forem do mesmo tipo, o pai fica com esse tipo
        else if (strcmp(node->s_type,"Add")==0 || strcmp(node->s_type,"Sub")==0 
        || strcmp(node->s_type,"Div")==0 || strcmp(node->s_type,"Mul")==0 || strcmp(node->s_type,"Mod")==0)
        {
            if(strcmp(node->filho->id, node->filho->irmao->id) != 0) node->id=(char*)strdup(" - double"); //os filhos sao de tipos diferentes 
            else node->id=(char*)strdup(node->filho->id);
        }
        
        else if(strcmp(node->s_type, "Assign")==0 || strcmp(node->s_type, "Minus")==0 || strcmp(node->s_type, "Plus")==0) node->id=node->filho->id;

        else if(strcmp(node->s_type,"Call")==0){
            
        }

    }else{
        return;
    }
}




tabela verifica_call(char ** parametros, int x, char * valor){

}



void check_ast(no raiz){
    if(raiz){
        if(strcmp(raiz->s_type, "MethodDecl")==0){

            char * params = verifica_method_params(raiz->filho->filho->irmao->irmao);
            char * valor = (char*)strdup(raiz->filho->filho->irmao->valor);

            char * n = malloc(strlen(params)+strlen(valor)+1);
            n[0]='\0';
            strcat(valor, params);
            strcat(n,valor);
            verifica_method_body(n,raiz->filho->irmao);
        }

    }else return;
    for(no aux = raiz->filho; aux!=NULL; aux=aux->irmao) check_ast(aux);
}