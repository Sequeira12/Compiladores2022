#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef enum {
	no_raiz,
	no_metodos,
	no_var,
	no_statements,
	no_operadores,
	no_terminais,
	no_ids
}tipo_no;


typedef struct node * no;
typedef struct node {
	char *valor;
	char * s_type;
	tipo_no tipo;
	no pai;
	no filho;
	no irmao;
	int num_node;
}node;





void AdicionaIrmao(no nod,no irmao);
void Arvore(no raiz, int pontos);
no CriaNo(tipo_no tipo, char *valor, char *s_type);
void AdicionaNo(no pai,no novo);
int conta_irmaos(no raiz);






