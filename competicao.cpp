#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
#include<fstream>
using namespace std;

typedef enum {A = 1, B, C, D} nacionalidade;

typedef struct {
	char nome[50];
	nacionalidade pais;
	int numero_de_notas;
	float *notas;
	float media; 
} competidor ;

competidor jogador[10];

int main(){
	FILE *pfile;
	int jurados;
	int competidores;
	int temppais;
	int escolha;
	char compname[20];
	cout << "///////////////////////////////////////////" << endl;
	cout << "############# COMPETIÇÃO XPTO #############" << endl;
	cout << "///////////////////////////////////////////" << endl;
	cout << "1 - Inserir competicao\n2 - Verificar competicao\n0 - sair" << endl;
	cout << "Opção: ";
	cin >> escolha;
	cout << "///////////////////////////////////////////" << endl;
	while(escolha){
		if(escolha == 1){//INSERIR COMPETIÇÃO
			cout << "Digite o nome da competição: ";
			cin >> compname; 
			cout << "Digite o número de competidores: ";
			cin >> competidores;
			while(competidores < 1){
				cout << "Número inválido! Digite novamente o número de competidores(>1): ";
				cin >> competidores;
			}
			cout << "Digite o número de jurados: ";
			cin >> jurados;
			while(jurados < 3){
				cout << "Número inválido! Digite novamente o número de jurados(>2): ";
				cin >> jurados;
			}
			cout << endl;
			cout << "//////////CADASTRAMENTO DE JOGADORES///////////" << endl;
			cout << endl;
			for (int i = 0; i<competidores; i++){//INSERIR COMPETIDORES
				cout << "JOGADOR " << i+1 << ":" << endl;
				cout << "Primeiro nome: ";
				cin >> jogador[i].nome;
				cout << "Pais (1 a 4): ";
				cin >> temppais;
				if (temppais == 1) jogador[i].pais = A;
				else if (temppais == 2) jogador[i].pais = B;
				else if (temppais == 3) jogador[i].pais = C;
				else if (temppais == 4) jogador[i].pais = D;
				jogador[i].notas = (float*) malloc (jurados*sizeof(float));
				cout << "Digite as " << jurados << " notas." << endl;

				for(int j=0; j<jurados; j++){//INSERIR NOTAS
					cin >> jogador[i].notas[j];
				}
				int b = jurados;
				for (int a=0; a < b; b--){//ORDENAÇÃO DE NOTAS
					for(int c =0; c<jurados-1; c++){
						if(jogador[i].notas[c]>jogador[i].notas[c+1]){
							float caixa = jogador[i].notas[c];
							jogador[i].notas[c] = jogador[i].notas[c+1];
							jogador[i].notas[c+1] = caixa;
						}
					}
				}
				jogador[i].media = 0;
				for(int a=1; a < jurados - 1; a++)//CALCULO DA MEDIA
					jogador[i].media += jogador[i].notas[a];
				jogador[i].media = jogador[i].media/(jurados-2);
				cout << endl;
			}
			int b = competidores;
			for (int a = 0; a<b; b--){//ORDENAÇÃO DE COMPETIDORES
				for (int c=0; c<competidores-1; c++){
					if(jogador[c].media<jogador[c+1].media){
						competidor caixa = jogador[c];
						jogador[c] = jogador[c+1];
						jogador[c+1] = caixa;
					}
				}
			}
			cout << endl;
			cout << "Posicao - Pais - Nome - notas validas" << endl;
			for (int i = 0; i<competidores; i++){//IMPRESSÃO DE RESULTADO
				cout << "   " << i+1 << "        ";
				cout << jogador[i].pais<< "   " << jogador[i].nome;
				cout << "     ";
				for(int j=1; j<jurados-1; j++){
					cout << jogador[i].notas[j] << " ";
				}
				cout << "		--média: " << jogador[i].media << endl;
			}
			cout << endl;
			cout << "O vencedor foi: " << jogador[0].nome << endl << endl;
			pfile = fopen(compname, "w");
			for(int i = 0; i < competidores; i++){//PASSAGEM PARA ARQUIVO
				fprintf (pfile,"%d %d ", i+1, jogador[i].pais);
				fprintf (pfile,"%s ", jogador[i].nome);
				fprintf (pfile,"%f \n", jogador[i].media);
			}
			fclose(pfile);
		}
		else if(escolha == 2){//IMPRIME CONTEÚDO DOS ARQUIVOS
			cout << "Digite o nome da competicao: ";
			cin >> compname;
			string line;
			ifstream myfile (compname);
			cout << "Posicao - Pais - Nome - media" << endl;
			if(myfile.is_open()){
				while (getline (myfile,line)){
					cout << line << endl;
				}
				myfile.close();
			}
		}
		cout << "///////////////////////////////////////////" << endl;
		cout << "############# COMPETIÇÃO XPTO #############" << endl;
		cout << "///////////////////////////////////////////" << endl;
		cout << "1 - Inserir competicao\n2 - Verificar competicao\n0 - sair" << endl;
		cout << "Opção: ";
		cin >> escolha;
		cout << "///////////////////////////////////////////" << endl;
	}
	return 0;
}
