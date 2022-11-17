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



void insere(no node, char * param_types, char * param, char * tabela_t){
    char * type = verifica_type(node->s_type);
    char * valor = node->irmao->valor;
    //printf("%s %s\n", type,valor);
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
    
    if(new->tab){// se a tabela ja tem elementos
        node_t t=new->tab;
        for(; t->next; t=t->next);//adicionamos o novo simbolo ao final da lista
        t->next=no_da_tabela;
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


char* procura_tabela(no node, char * tab){
    char * nome = node->valor;
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
    return strdup("- undef");
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