#include <stdio.h>

int cursor1= -1, cursor2=8;
int vetor[8];

void inserir(int variavel, int qualpilha){

	if(qualpilha==1){//estamos na pilha1
			if(cursor1 +1 == cursor2||cursor1==7){
		printf("O vetor nao possui mais espaco..\n");
		return;
	}
		cursor1++;
		vetor[cursor1] = variavel;
	}else{
		if(qualpilha==2){//estamos na pilha 2, ela vai da direita pra esquerda
			if(cursor1 == cursor2-1 ||cursor2==0){
			printf("O vetor nao possui mais espaco..\n");
			return;
			}
		cursor2--;
		vetor[cursor2] = variavel;
		}
	}
}

void remover(int qualpilha){
	if(qualpilha==1){
		if(cursor1==-1){
			printf("Pilha vazia.\n");
			return ;
		}else{
			printf("Numero %d removido.\n", vetor[cursor1]);
			cursor1--;			
		}
		}
		else{
				if(qualpilha==2){
					if(cursor2==8){
						printf("Pilha vazia.\n");
						return ;
					}else{
						printf("Numero %d removido.\n", vetor[cursor1]);
						cursor1++;			
				}
			}
		}
}


int main(){
	remover(1);
	remover(2);
	inserir(1,1);
	inserir(2,1);
	inserir(3,1);
	inserir(4,1);
	inserir(5,1);
	inserir(6,1);
	inserir(7,1);
	inserir(8,1);
	inserir(9,1);
	
	 //imprime a fila 1 
	 for(int i=0; i<cursor1+1 ; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");
	remover(2);
	remover(1);
	
	//imprime a fila 1:
	for(int i=0; i<cursor1+1 ; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");
	
	remover(1);
	remover(1);
	remover(1);
	remover(1);

	//imprime a fila 1:
	for(int i=0; i<cursor1+1 ; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");	
	
	inserir(16,2);
	inserir(17,2);
	inserir(18,2);
	inserir(19,2);
	inserir(20,2);	
	inserir(21,2);	

	
	//imprime a pilha 2
	for( int i=cursor2; i<8 ; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n\n");
	//imprime a fila 1:
	for(int i=0; i<cursor1+1 ; i++){
		printf("%d ", vetor[i]);
	}	
			
	return 0;
}
