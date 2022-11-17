#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "functions.h"


typedef struct node_table* node_t;
typedef struct node_table {
    char * valor;
    char * s_type;
    char * param_types;
    char * param;
    node_t next;
} node_table;

typedef struct table* tabela;
typedef struct table{
    char * type;
    char * nome;
    char * c_nome;
    char ** array_params;
    int n_params;
    node_t tab;
    tabela next;
}table;



void insere(no no, char * param_types, char * param, char * tabela_t);
void nova_classe(char * valor);
char * verifica_type(char* tipo);

char* procura_tabela(no node, char * tab);
void novo_metodo(char *nome, char * valor, char ** array_de_parametros, char * tipo);
void imprime_tabela();
tabela procura_tab(char * n);

tabela check_call(char * id, char ** params, int p);
int verifica_repetidos(char * n);

#endif