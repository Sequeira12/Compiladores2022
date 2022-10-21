#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct node{
	char *nome;
	struct node* filho;
	struct node* irmao;
}node;


int conta_irmaos(node* raiz);
node* NovoNo(char* nome);
void AdicionaIrmao(node* no, node* irmao);
void AdicionaFilho(node* no, node* filho);
node* NovoID(char* nome, char* valor);
void print_tree(int level, node* n);
void free_tree(node* n);
