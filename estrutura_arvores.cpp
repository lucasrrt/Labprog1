#include<iostream>
#include<vector>

using namespace std;

class No{
public:
	int x;
	No *esquerda;
	No *direita;
	No(int x) : 
		x(x), esquerda(NULL), direita(NULL) {};
	No():
		x(0), esquerda(NULL), direita(NULL) {};
};

class ArvoreBinaria{
	public:
	vector<No> arvore;
public:
	ArvoreBinaria (No &raiz){
		arvore.push_back(raiz);
	}
	No busca(int chave, No &ptr){
		if(ptr==NULL){
			return ptr;
		}
		else{
			if(chave == ptr->x)
				return ptr;
			else if(chave < ptr->x)
				busca(chave, ptr->esquerda);
			else
				busca(chave, ptr->direita);
		}
		return ptr;
	}
	void inserir(int chave, No *raiz){
		No *ptr = raiz;
		No *aux;
		aux = busca(chave, &arvore[0]);
		if(aux == NULL){
			while(ptr != NULL){
				if(chave < ptr->x)
					ptr = ptr->esquerda;
				else
					ptr = ptr->direita;
			}
			if(ptr == NULL){
				ptr->x = chave;
				cout << ptr->x << endl;
				arvore.push_back(*ptr);
			}
		}
	}
	void showArvore(){
		int i=0;
		while(i<2){
			cout << arvore[i].x << endl;
			i++;
		}
	}
};

int main(){
	No raiz(20);
	ArvoreBinaria lol(raiz);
	lol.inserir(10, &raiz);
	lol.inserir(30, &raiz);
	lol.showArvore();
	return 0;
}
