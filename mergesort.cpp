#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int v[8];//vetor a ser ordenado
int r[8];//memoria auxiliar

void merge(int inicio, int fim){
	int m = (inicio+fim)/2;
	int aux=inicio;
	int i1 = inicio, f1 = m;
	int i2 = f1+1, f2 = fim;
	if (inicio==fim)
		return ;
	else{
		merge(i1, f1);
		merge(i2, f2);
	}
	//Intercalar as duas metades
	while(i1<=f1 && i2<=f2){
		if(v[i1]<v[i2]){
			r[aux]=v[i1];
			i1++;
		}
		else {
			r[aux] = v[i2];
			i2++;
		}
		aux++;
	}
	while(i1<=f1){
		r[aux]=v[i1];
		i1++;
		aux++;
	}
	while(i2<=f2){
		r[aux] = v[i2];
		aux++;
		i2++;
	}
	for(aux = inicio; aux<=fim; aux++)
		v[aux] = r[aux];
}

int main() {
	int cont = 0;
	for(cont = 0; cont < 8; cont++)
		//v[cont]=8 - cont;
		scanf("%d", v+cont);
	merge(0, 7);
	for(cont = 0; cont<8; cont++)
		printf("%d ", v[cont]);
	printf("\n");
	return 0;
}
