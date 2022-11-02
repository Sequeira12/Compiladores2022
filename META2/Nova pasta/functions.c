#include "functions.h"





//-------------------------------------------------//

no CriaNo(tipo_no tipo, char *valor, char *s_type){
	no novo = malloc(sizeof(node));
	novo->s_type = (char *)malloc(1 + strlen(s_type) * sizeof(char));
	strcpy(novo->s_type,s_type);
	novo->valor = (char *) malloc(1 + strlen(valor) * sizeof(char));
	strcpy(novo->valor,valor);
	novo->tipo = tipo;
	novo->num_node = 0;
	novo->pai = NULL;
	novo->filho = NULL;
	novo->irmao = NULL; 

}

void AdicionaNo(no pai,no novo){
    if(novo == NULL){
    	return;
    }
    pai->filho = novo;
    pai->num_node++;
    novo->pai = pai;
}	

int conta_irmaos(no raiz){
   int conta = 0;
   no aux;
   aux = raiz;
   while(aux != NULL){
   	aux = aux->irmao;
   	conta++;
   }
   return conta;
	
}

void AdicionaIrmao(no nod,no irmao){
	if(nod == NULL || irmao == NULL){
	   return;
	}
	no aux;
	aux = nod;
	while( aux->irmao != NULL){
	   aux = aux->irmao;
	}   
	aux->irmao = irmao;
	if(nod->pai != NULL){
	  irmao->pai = nod->pai;
	  irmao->pai->num_node++;
	}
}


void Arvore(no raiz, int pontos){
	if(raiz == NULL){
          return;
	}
	int i = 0;
	no aux;
	
	if(raiz->tipo == no_raiz){
		printf("%s\n",raiz->s_type);
	}else{
   	   while(i < pontos){
   	   	printf("..");
   	   	i++;
   	   }
   	   if(strcmp(raiz->valor,"")!=0){
   	   	printf("%s(%s)\n",raiz->s_type,raiz->valor);	
   	   }else{
   	   	printf("%s\n",raiz->s_type);
   	   }	
	}
	aux = raiz->filho;
	while(aux!=NULL){
		no aux_free = aux;
		Arvore(aux,pontos+1);
		aux = aux->irmao;
		free(aux_free->valor);
		free(aux_free->s_type);
		free(aux_free);
	}	
		
}

