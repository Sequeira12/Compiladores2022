 //Rui Santos 2020225542
 //Bruno Sequeira 2020235721

#include "functions.h"



no CriaNo(char *id[3], char *valor, char *s_type){
	no novo = malloc(sizeof(node));
	novo->s_type = (char *)malloc(1 + strlen(s_type) * sizeof(char));
	if(valor){
		novo->valor = (char *) malloc(1 + strlen(valor) * sizeof(char));
		strcpy(novo->valor,valor);
		if(id){
		novo->line=id[1];
		//printf("%s %s\n",s_type, novo->line);
		novo->col=id[2];
		}
	}else{
		novo->valor = (char *) malloc(1 + strlen(id[0]) * sizeof(char));
		strcpy(novo->valor,id[0]);

		novo->line=id[1];
		//printf("%s %s\n",s_type, novo->line);
		novo->col=id[2];
	}
	strcpy(novo->s_type,s_type);
	novo->pai = NULL;
	novo->irmao = NULL;
	novo->filho = NULL; 
	novo->num_node = 0;
}

void AdicionaNo(no pai,no novo){
    if(novo){
		pai->filho = novo;
		pai->num_node++;
		novo->pai = pai;
    }else return;
}	

int conta_irmaos(no raiz){
   int conta = 0;
   no aux=raiz;
   for(aux=raiz;aux!=NULL; aux=aux->irmao) conta++;
   return conta;
}

void AdicionaIrmao(no nod,no irmao){
	if(nod && irmao){
		no aux;
		for(aux=nod; aux->irmao; aux=aux->irmao);
	
		aux->irmao = irmao;
		if(nod->pai){
			irmao->pai = nod->pai;
			irmao->pai->num_node++;
		}
	}else return;

}


void Arvore(no raiz, int pontos,int anotada){
	if(raiz){	
		if(strcmp(raiz->s_type,"Program")==0) printf("%s\n",raiz->s_type);
		else{
			for(int i = 0; i<pontos; i++)printf("..");

			if(strcmp(raiz->valor,"")!=0){
				if(anotada==1 && raiz->id!=NULL) printf("%s(%s)%s\n",raiz->s_type,raiz->valor, raiz->id);
				else printf("%s(%s)\n",raiz->s_type,raiz->valor);
				
			}	
			else{
				if(anotada==1 && raiz->id!=NULL)printf("%s%s\n",raiz->s_type, raiz->id);
				else printf("%s\n",raiz->s_type);	
			}
		}
		no aux = raiz->filho;
		//prints and cleans tree
		while(aux!=NULL){
			no aux_free = aux;
			Arvore(aux,pontos+1,anotada);
			aux = aux->irmao;
			free(aux_free->valor);
			free(aux_free->s_type);
			free(aux_free);
		}
	}else return;
}


