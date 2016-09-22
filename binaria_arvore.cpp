#include<stdio.h>
#include<stdlib.h>

struct no{
	int chave;
	struct no *esq;
	struct no *dir;
};

void print_pre (struct no *raiz){
	if(raiz){
		printf("%d, ", raiz->chave);
		print_pre(raiz->esq);
		print_pre(raiz->dir);
	}
}

struct no *busca (int chave, struct no *raiz, int *f, int *esq, struct no **pai){
	struct no *aux = raiz;
	if(raiz == NULL){//arvore vazia
		*f = 0;
		*pai = NULL;
		return NULL;
	}
	else{
		if(aux->chave == chave){
			*f=1;
			return aux;
		}
		else{
			if(chave < aux->chave){
				if(aux->esq){
					*pai = aux;
					aux = aux->esq;
					*esq = 1;
					return busca(chave, aux, f, esq, pai);
				}
				else{
					*f = 2;
					return aux;
				}
			}
			else{
				if(aux->dir){
					*pai = aux;
					aux = aux->dir;
					*esq = 0;
					return busca(chave, aux, f, esq, pai);
				}
				else{
					*f=3;
					return aux;
				}
			}
		}
	}
}

int inserir(int chave, struct no **raiz){
	struct no *aux, *pai, *novo;
	int f, esq;
	aux = busca(chave, *raiz, &f, &esq, &pai);
	if(f==1)
		return 0;
	else{
		novo = (struct no*) malloc(sizeof(struct no));
		novo->dir = NULL;
		novo->esq = NULL;
		novo->chave = chave;
		if(aux){
			if(chave < aux->chave)
				aux->esq = novo;
			else
				aux->dir = novo;
		}
		else
			*raiz = novo;
		return 1;
	}
}

struct no *remover(int chave, struct no **raiz){
	struct no *aux, *pai=NULL, *sub;
	int f, esq;
	aux = busca(chave,*raiz, &f, &esq, &pai);
	if(f==1){
		if((aux->esq == NULL)&&(aux->dir == NULL)){//caso 1
				if(pai){
					if(esq){
						pai->esq = NULL;
						return aux;
					}
					else{
						pai->dir = NULL;
						return aux;
					}
				}
				else{
					*raiz = NULL;
					return aux;
				}
		}
		else if((aux->esq == NULL)||(aux->dir == NULL)){//caso 2
			if(pai){
				if(esq)
					pai->esq = aux->esq?aux->esq:aux->dir;
				else
					pai->dir = aux->esq?aux->esq:aux->dir;
				return aux;
			}
			else{
				*raiz = aux->esq?aux->esq:aux->dir;
				return aux;
			}
		}
		else{//caso 3
			int f1, esq1;
			struct no *pai1;
			sub = busca(chave, aux->esq, &f1,&esq1,&pai1);
			sub = remover(sub->chave, raiz);
			if(pai){
				if(esq)
					pai->esq = sub;
				else
					pai->dir = sub;
				sub->dir = aux->dir;
				sub->esq = aux->esq;
			}
			return aux;
		}
	}
	return NULL;
}

int main(){
	struct no *raiz = NULL;

	inserir(40, &raiz);
	inserir(20, &raiz);
	inserir(30, &raiz);
	inserir(10, &raiz);
	inserir(70, &raiz);
	inserir(80, &raiz);
	inserir(15, &raiz);
	inserir(18, &raiz);
	inserir(5, &raiz);
	print_pre(raiz);
	printf("\n");
	free(remover(20, &raiz));
	print_pre(raiz);
	printf("\n");
}
