#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct reg {
	int conteudo;
	struct reg *prox;
} celula;

void imprime (celula *le) {
	if (le != NULL) {
		printf("%d\n", le->conteudo);
		imprime(le->prox);
	}
}

void imprime2 (celula *le) {
	celula *p;
	for(p=le; p!=NULL; p=p->prox)
		printf("%d\n", p->conteudo);
}

int contar(celula *le){
	if (le!=NULL)
		return 1+contar(le->prox);
	else 
		return 1;
}

int contar2 (celula *le) {
	int n = 0;
	celula *p;
	for(p = le; p != NULL; p=p->prox) n++;
	return n;
}

int altura (celula *c){
	if(c!=NULL)
		return 1 + altura(c->prox);
	else
		return 1;
}

int altura2 (celula *c){
	int n = 0;
	celula *p;
	for(p=c;p!=NULL;p=p->prox)
		n++;
	return n;
}
int profundidade (celula *le, celula *c) {
	if(le!=c)
		return 1+profundidade(le->prox, c);
	else
		return 1;
}

int profundidade2 (celula *le, celula *c){
	int n = 0;
	celula *p;
	for(p=le; p != c; p=p->prox)
		n++;
	return n;
}

celula *buscar (int x, celula *le){
	celula *p;
	p=le;
	while(p!=NULL && p->conteudo != x)
		p=p->prox;
	return p;
}

celula *buscar2 (int x, celula *le){
	if(le == NULL) return NULL;
	if(le->conteudo == x) return le;
	return buscar2(x, le->prox);
}

void insere (int x, celula *p){
	celula *nova;
	nova = (celula*) malloc(sizeof(celula));
	nova->conteudo = x;
	nova->prox = p->prox;
	p->prox = nova;
}

int main(void){
	printf("sizeof(celula) = %d\n", (int) sizeof(celula));
	return 0;
}
