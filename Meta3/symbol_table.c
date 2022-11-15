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
    char * valor = (char*)strdup(node->irmao->valor);
    printf("aqui %s\n", type);
    node_t no_da_tabela = calloc(1,sizeof(node_t));
    no_da_tabela->valor=valor;
    no_da_tabela->s_type=type;
    no_da_tabela->next=NULL;

    if (param) no_da_tabela->param=param;
    if (param_types) no_da_tabela->param_types=param_types;

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


void imprime_tabela(){
    for(tabela aux = tabela_simbolos; aux!=NULL; aux=aux->next){
        printf("===== %s %s Symbol Table =====\n", aux->type, aux->nome);
        for(node_t auxi = aux->tab; auxi!=NULL; auxi=auxi->next){
            if (auxi->param==NULL) printf("%s\t\t%s\t%s\n", auxi->valor, auxi->s_type, auxi->param);
            else printf("%s\t%s\t%s\n", auxi->valor, auxi->param_types, auxi->s_type);
        }
        printf("\n");
    }
}



tabela procura_tab(char * n){
    tabela i = tabela_simbolos;
    for(i; i!=NULL && (strcmp(i->nome,n)!=0); i=i->next)
    return i;
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


void novo_metodo(char *nome, char * valor, char ** array_de_parametros, char * tipo){
    tabela node = calloc(1,sizeof(table));
    node->type = (char*)calloc((strlen("Method")+1), sizeof(char));

    
}


char* procura_tabela(no node, char * tab){
    node->valor;
}