#include<iostream>

using namespace std;

struct lista{
	int x;
	struct lista *proximo;
};

int v[10];
int contador = 1;
void quicksort(int inicio, int fim){
	int pivo;
	int j = inicio+1;
	int caixa;
	for(pivo = inicio; j<=fim; j++){
		if((v[pivo]>v[j]&&pivo<j)||(v[pivo]<v[j]&&pivo>j)){
			caixa = v[j];
			v[j] = v[pivo];
			v[pivo] = caixa;
			caixa = pivo;
			pivo = j;
			j = caixa;
		}
	}
	if(pivo-1 > inicio)
		quicksort(inicio,pivo-1);
	if(fim > pivo+1)
		quicksort(pivo+1, fim);
	cout << contador << " Ordenação concluída!" << endl;
	contador++;
}

void imprimir(){
	for(int i = 0; i < 8; i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(){
	int n = 8;
	//for(int i = 0; i < 8; i++){
	//	v[i] = n;
	//	n--;
	//}
	v[0]=8;
	v[1]=7;
	v[2]=6;
	v[3]=5;
	v[4]=4;
	v[5]=3;
	v[6]=2;
	v[7]=1;
	imprimir();
	quicksort(0,7);
	imprimir();
	return 0;
}
