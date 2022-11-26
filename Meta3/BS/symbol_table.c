#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "symbol_table.h"
#include "semantics.h"


tabela tabela_simbolos;

//cria a tabela de simbolos
void nova_classe(char * valor){
    tabela_simbolos= calloc(1, sizeof(table));
    tabela_simbolos->type = (char*)calloc((strlen("Class")+1), sizeof(char));
    tabela_simbolos->nome = (char*)calloc((strlen(valor)+1), sizeof(char));
    strcpy(tabela_simbolos->type, "Class");
    strcpy(tabela_simbolos->nome, valor);
    tabela_simbolos->array_params=NULL;
}


//verificar se existem parametros iguais para nao inserir repetidos
int verifica_repetidos_parametros(char *n,char * valor){
    for(tabela aux = tabela_simbolos; aux!=NULL; aux=aux->next){
        if(strcmp(aux->nome,n)==0){
            for(node_t auxi = aux->tab; auxi!=NULL; auxi=auxi->next){
                if(strcmp(auxi->valor,valor)==0 && strcmp(auxi->param,"param")==0) return 1;
            }
        }
    }
    return 0;
}

void insere(no node, char * param_types, char * param, char * tabela_t){
    char * type = verifica_type(node->s_type);
    char * valor = node->irmao->valor;
   
    if(strcmp(valor,"_")==0){
        //printf("%s\n", node->pai->col);
        printf("Line %s, col %s: Symbol _ is reserved\n",node->pai->line,node->pai->col);
        return;
    }
    node_t no_da_tabela = calloc(1000,sizeof(node_t));
    no_da_tabela->valor=valor;
    no_da_tabela->s_type=type;
    no_da_tabela->next=NULL;
    if (param_types) {
        no_da_tabela->param_types = param_types;
                //printf("%s\n", param_types);
    }
    else {
        no_da_tabela->param_types = "";
    }
    if (param) {
               // printf("%s\n", param);
        no_da_tabela->param = param;
    }
    else {
        no_da_tabela->param = "";
    }
    tabela new = NULL;

    if(strcmp(tabela_t, "Class")==0) new=tabela_simbolos;
    else new=procura_tab(tabela_t);
   // if(strcmp(node->id,"_")==0){
   //     printf("NTROU\n");
   // }
    if(new->tab){// se a tabela ja tem elementos
       //printf("inserir->%s %s\n", valor,new->nome);strcmp(t->s_type, node->s_type)==0 &&
        node_t t=new->tab;
        for(; t->next; t=t->next){//compara até ao penultimo simbolo da tabela
            if(strcmp(t->valor,valor)==0 && (strcmp(node->pai->s_type,"VarDecl")==0 || (strcmp(node->pai->s_type,"FieldDecl")==0) && strcmp(t->s_type,verifica_type(node->s_type))==0)){
                            //printf("%s %s \n",t->s_type, node->valor);
                printf("Line %s, col %s: Symbol %s already defined\n", node->irmao->line, node->irmao->col, node->irmao->valor);
                return;
            }
        }
        //compara com o ultimo simbolo da tabela
        if(strcmp(t->valor,valor)==0 && (strcmp(node->pai->s_type,"VarDecl")==0 || (strcmp(node->pai->s_type,"FieldDecl")==0) && strcmp(t->s_type,verifica_type(node->s_type))==0)){
           // printf("%s %s \n",t->s_type, node->s_type);
            printf("Line %s, col %s: Symbol %s already defined\n", node->irmao->line, node->irmao->col, node->irmao->valor);
            return;
        }
        t->next=no_da_tabela;//adicionamos o novo simbolo ao final da lista
    }else{
        //o novo simbolo vai ser colocado no inicio da lista
        new->tab=no_da_tabela;
    }

}




int verifica_repetidos(char * n){

    for(tabela aux = tabela_simbolos; aux!=NULL; aux=aux->next){
            if (strcmp(aux->nome,n)==0){
                return -1;
            }    
    }
   
    return 1;
}

char * retornaTipo(no node){
    for(tabela aux = tabela_simbolos; aux!=NULL; aux=aux->next){
        for(node_t auxi = aux->tab; auxi!=NULL; auxi=auxi->next){
            
            if(auxi->valor!=NULL && node->valor!=NULL){
            if (strcmp(auxi->valor,node->valor)==0)return auxi->s_type;   
            } 
        }
    }
}


void imprime_tabela(){
    for(tabela aux = tabela_simbolos; aux!=NULL; aux=aux->next){
        printf("===== %s %s Symbol Table =====\n", aux->type, aux->nome);
        for(node_t auxi = aux->tab; auxi!=NULL; auxi=auxi->next){
            if (strcmp(auxi->param,"")!=0) printf("%s\t\t%s\t%s\n", auxi->valor, auxi->s_type, auxi->param);
            else printf("%s\t%s\t%s\n", auxi->valor, auxi->param_types, auxi->s_type);
        }
        printf("\n");
    }
}



//mudei aquiii
tabela procura_tab(char * n){
    tabela i = tabela_simbolos;
    tabela aux = NULL;
    while(i) {
        if (strcmp(i->nome, n) == 0) {
            aux = i;
        }
        i = i->next;
    }

    return aux;
}



char * verifica_type(char* tipo){        
    if (strcmp(tipo, "StringArray") == 0) return "String[]";
    else if (strcmp(tipo, "Int") == 0) return "int";
    else if (strcmp(tipo, "Double") == 0) return "double";
    else if (strcmp(tipo, "Bool") == 0) return "boolean";
    else if (strcmp(tipo, "Void") == 0) return "void";
    else if (strcmp(tipo, "ParseArgs") == 0) return "int";
    return NULL;
}

void insere_elemento(char * valor, char * s_type, char * param_types, char * param, tabela tabela_t) {
    node_t n_node = calloc(1, sizeof(node_table));

    n_node->valor = valor;
    n_node->s_type = s_type;
    n_node->next = NULL;
    if (param_types) {
        n_node->param_types = param_types;
    }
    else {
        n_node->param_types = "";
    }
    if (param) {
        n_node->param = param;
    }
    else {
        n_node->param = "";
    }
    tabela_t->tab = n_node;
}

void novo_metodo(char *nome, char * valor, char ** array_de_parametros, char * tipo){
    tabela node = calloc(1,sizeof(table));
    node->type = (char*)calloc((strlen("Method")+1), sizeof(char));
    strcpy(node->type, "Method");
    node->nome=nome;
    node->c_nome=valor;
    node->array_params=array_de_parametros;
    
   /* for(int i=0; i<30 && array_de_parametros[i]!=NULL;i++){
        printf("%s ",array_de_parametros[i]);
    }printf("\n");*/

    tabela h = tabela_simbolos;
    if (h == NULL) {
        tabela_simbolos = node;
    }
    else {
        while (h->next) {
            h = h->next;
        }
        h->next = node;
    }
    insere_elemento("return", tipo, NULL, NULL, h->next);
    
}

char * verificaAmbiguidade(char *nome , char **params){
    tabela h = tabela_simbolos;
   
    tabela aux_node = tabela_simbolos;
  
    for(aux_node = tabela_simbolos; aux_node; aux_node = aux_node->next){
        if(aux_node->array_params != NULL){
           
            if(strcmp(nome,aux_node->c_nome) == 0 && strcmp(params[0],aux_node->array_params[0])==0){
                if(Diferenca(params,aux_node->array_params)!=atoi(params[0])){
                    return aux_node->type;
                }    
            }
            
        }
    }
    return "FALSE";
}
int Diferenca(char ** ParamT, char ** ParamC){
    int numP = atoi(ParamT[0]);
   
    int contador = 0;
    for(int i = 1; i <= numP;i++){
      
        if(strcmp(ParamT[i],ParamC[i])==0){
            contador++;
        }
    }
   
    return contador;
}


char* procura_tabela(no node, char * tab){
    char * nome = node->valor;
    //printf("%s   ", node->id);
    tabela aux = NULL;
    node_t aux_node = NULL;
    char string[500] = " - ";
    aux = procura_tab(tab);
    if (aux) {
        for (aux_node = aux->tab; aux_node; aux_node = aux_node->next) {
            if (strcmp(aux_node->valor, nome) == 0) {
                strcat(string, aux_node->s_type);
                return strdup(string);
            }
        }
    }
    aux = tabela_simbolos;
    for (aux_node = aux->tab; aux_node; aux_node = aux_node->next) {
        if (strcmp(aux_node->valor, nome) == 0 && strcmp(aux_node->param_types, "") == 0) {
            strcat(string, aux_node->s_type);
            return strdup(string);
        }

    }
     return strdup(" - undef");
}



char ** retorna_variaveis_parametros(char* tab){
    char** vars= (char**)malloc(100*sizeof(char*));;
    int i = 0;

    

    for(node_t auxi = tabela_simbolos->tab; auxi!=NULL; auxi=auxi->next){
        vars[i]=auxi->valor;
        i++;
    }


    for(tabela aux = tabela_simbolos; aux!=NULL; aux=aux->next){
        if(strcmp(aux->nome, tab)==0){
            for(node_t auxi = aux->tab; auxi!=NULL; auxi=auxi->next){
                vars[i] = auxi->valor;
                i++;
            }
        }
    }
    if(i>0) return vars;
    return NULL;
}



tabela check_call(char * id, char ** params, int p) {
    tabela head = tabela_simbolos->next;
    while (head != NULL) {
        if (strcmp(head->c_nome, id) == 0) {
            if (head->array_params != NULL && params != NULL) {
                if (strcmp(head->array_params[0], params[0]) == 0) {
                    int i;
                    int j = atoi(params[0]);
                    int tab = 0;
                    for (i = 1; i <= j; i++) {
                        if (p == 1) {
                            if (strcmp(head->array_params[i], params[i]) != 0 && !(strcmp(head->array_params[i], "double") == 0 && strcmp(params[i], "int") == 0)) {
                                tab = 1;
                            }
                        }
                        else {
                            if (strcmp(head->array_params[i], params[i]) != 0) {
                                tab = 1;
                            }
                        }
                    }
                    if (tab == 0) {
                        return head;
                    }
                }
            }
        }
        head = head->next;
    }
    if (p == 0) {
        return check_call(id, params, 1);
    }
    return NULL;
}