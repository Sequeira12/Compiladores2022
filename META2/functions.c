#include "functions.h"

node* NovoNo(char* nome){
	node* no = (node *) malloc(sizeof(node));
	no->nome = strdup(nome);
	no->filho = NULL;
	no->irmao = NULL;
	return no;
}

void AdicionaIrmao(node* no, node* irmao){
	node* auxiliar = no;
	if(no!=NULL && irmao != NULL){
		while(auxiliar->irmao != NULL){
			auxiliar = auxiliar->irmao;
		}
		auxiliar->irmao = irmao;
	}
}

void AdicionaFilho(node* no, node* filho){
	if(no!=NULL && filho != NULL){
		if(no->filho == NULL){
			no->filho = filho;
		}else{
			AdicionaIrmao(no->filho, filho);
		}
	}			
}

node* NovoID(char* nome, char* valor){
	int len = strlen(nome) + strlen(valor) + 3;
	char str[len];
	node* no = (node *) malloc(sizeof(node));
	sprintf(str,"%s(%s)",nome, valor);
	no->nome = strdup(str);
	no->filho = NULL;
	no->irmao = NULL;
}


int conta_irmaos(node* raiz) {
		int conta = 0;
		node* aux;
		aux = raiz;
		while (aux != NULL) {
			aux = aux->irmao;
			conta++;
		}
		return conta;
	}
	
	
	
void print_tree(int level, node* n){
if (n == NULL) return;
    if (strcmp(n->nome, "Vazio") != 0){
            for (int i = 0; i < level; i++) {
                printf("..");
            }
           printf("%s\n", n->nome);
    }
    print_tree(level + 1, n->filho);
    print_tree(level, n->irmao);

}

void free_tree(node* n){
    if (n == NULL) return;
    if(n->irmao!=NULL)
        free_tree(n->irmao);
    if(n->filho!=NULL)
        free_tree(n->filho);
    free(n);
}




