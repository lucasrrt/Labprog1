//Simulador de quadribol
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Jogador{
	private:
		string nome;
		int posicao;//1-goleiro; 2-apanhador; 3-batedor; 4-artilheiro
		int forca, velocidade, estilo;
		int habilidadeIndividual;
	public:
		Jogador(string nome, int forca, int velocidade, int estilo):nome(nome), forca(forca), velocidade(velocidade), estilo(estilo){};
		void setHabilidadeIndividual(int habilidadeIndividual){this->habilidadeIndividual = habilidadeIndividual;}
		int  getHabilidadeIndividual(){return habilidadeIndividual;}
		void setposicao(int posicao){this->posicao = posicao; }
		int  getposicao(){return posicao;}
};

class Artilheiro:public Jogador{
	private:
		int truquesDoChapeu;
	public:
		Artilheiro(string nome, int forca, int velocidade, int estilo, int truquesDoChapeu):Jogador(nome, forca, velocidade, estilo),truquesDoChapeu(truquesDoChapeu){
			setHabilidadeIndividual(forca+3*velocidade+2*estilo+20*truquesDoChapeu);
			setposicao(4);
		}; 
};

class Batedor:public Jogador{
	private:
		int balacosAfastados;
	public:
		Batedor(string nome, int forca, int velocidade, int estilo, int balacosAfastados):Jogador(nome, forca, velocidade, estilo),balacosAfastados(balacosAfastados){
			int x = 1;
			for(int i = 0; i < balacosAfastados/100;i++)
				x*=2;
			setHabilidadeIndividual((3*forca+velocidade+estilo)*x);
			setposicao(3);
		}; 
};

class Apanhador:public Jogador{
	private:
		int pomosDeOuro;
	public:
		Apanhador(string nome, int forca, int velocidade, int estilo, int pomosDeOuro):Jogador(nome, forca, velocidade, estilo),pomosDeOuro(pomosDeOuro){
			setHabilidadeIndividual(forca+2*velocidade+3*estilo+10*pomosDeOuro);
			setposicao(2);
		}; 
};

class Goleiro:public Jogador{
	private:
		int camisasLimpas;
		int jogos;
	public:
		Goleiro(string nome, int forca, int velocidade, int estilo, int camisasLimpas, int jogos):Jogador(nome, forca, velocidade, estilo),camisasLimpas(camisasLimpas), jogos(jogos){
			setHabilidadeIndividual(2*forca+3*estilo-(jogos-camisasLimpas));
			setposicao(1);
		}; 
};

class QuadribolTime{
	private:
		string nomeDaEquipe;
		vector<Jogador> vetJogadores;
		bool validade;//Checa se o time será valido
		int numeroDeJogadores;
		int artilheiros, apanhadores, batedores, goleiros;
	public:
		QuadribolTime(string nomeDaEquipe):nomeDaEquipe(nomeDaEquipe){
			validade = 1;
			numeroDeJogadores = 0;
			artilheiros=0;
			apanhadores=0;
			batedores=0;
			goleiros=0;
		};
		string getNome(){ return nomeDaEquipe; }

		void adicionarJogador(Jogador &jo){
			if(numeroDeJogadores<7){
				vetJogadores.push_back(jo);
				numeroDeJogadores++;
				if(jo.getposicao() == 1)
					goleiros++;
				if(jo.getposicao() == 2)
					apanhadores++;
				if(jo.getposicao() == 3)
					batedores++;
				if(jo.getposicao() == 4)
					artilheiros++;
				if(goleiros>1||apanhadores>1||batedores>2||artilheiros>3)
					validade = 0;
			}
		}

		void alterarJogador(int indice, Jogador &jo){
			if(vetJogadores[indice].getposicao()==1)
				goleiros--;
			if(vetJogadores[indice].getposicao()==2)
				apanhadores--;
			if(vetJogadores[indice].getposicao()==3)
				batedores--;
			if(vetJogadores[indice].getposicao()==4)	
				artilheiros--;

			vetJogadores[indice]=jo;

			if(jo.getposicao()==1)
				goleiros++;
			if(jo.getposicao()==2)
				apanhadores++;
			if(jo.getposicao()==3)
				batedores++;
			if(jo.getposicao()==4)
				artilheiros++;

			if((goleiros==1) && (apanhadores==1) && (batedores==2) && (artilheiros == 3))
				validade = 1;
			else
				validade = 0;
		}

		int pegarHabilidadeTotal(){
			if(validade == 0){
				return -1;
			}
			if(numeroDeJogadores < 7){
				return -1;
			}
			else{
				int habilidadeTotal = 0;
				for(int i = 0; i < 7; i++){
					habilidadeTotal += vetJogadores[i].getHabilidadeIndividual();
				}
				return habilidadeTotal;
			}
		}
};

class Partida{
	private:
	public:
		bool realizar(QuadribolTime q1, QuadribolTime q2, string &resultado){
			if(q1.pegarHabilidadeTotal() == -1 || q2.pegarHabilidadeTotal() == -1)
				return 0;//partida invalida
			else{
				if(q1.pegarHabilidadeTotal() > q2.pegarHabilidadeTotal())
					resultado = q1.getNome();
				if(q1.pegarHabilidadeTotal() < q2.pegarHabilidadeTotal())
					resultado = q2.getNome();
				if(q1.pegarHabilidadeTotal() == q2.pegarHabilidadeTotal())
					resultado = "Empate";
				return 1;//Partida Valida
			}
		}
};

int main(){

	Goleiro go1("Ron Weasley", 5, 3, 4, 10, 20); //nome, forca, velocidade, estilo, Qtde de Camisas Limpas, Qtde de Jogos
	Apanhador ap1("Harry Potter", 3, 2, 6, 10);  //nome, forca, velocidade, estilo, Qtde de Pomos de Ouro
	Batedor ba1("Jimmy Peakes", 3, 6, 4, 8),     //nome, forca, velocidade, estilo, Qtde de Balaços afastados
			ba2("Ritchie Coote", 3, 6, 3, 7);
	Artilheiro ar1("Demelza Robins", 5, 7, 3, 8),//nome, forca, velocidade, estilo, Qtde de Truques do Chapéu
			   ar2("Ginny Weasley", 10, 7, 3, 2),
			   ar3("Katie Bell", 2, 7, 4, 4);

	Goleiro go2("Miles Bletchley", 5, 3, 4, 10, 50);
	Apanhador ap2("Draco Malfoy", 5, 1, 5, 20);
	Batedor ba4("Vincent Crabbe", 3, 6, 4, 8),
			ba5("Gregory Goyle", 3, 6, 3, 7);
	Artilheiro ar4("Graham Montague", 5, 7, 3, 8),
			   ar5("Adrian Pucey", 10, 7, 3, 2),
			   ar6("Cassius Warrington", 2, 7, 4, 0);

	QuadribolTime q1("Grifinoria"), //nome
				  q2("Sonserina");


	q1.adicionarJogador(go1);//adiciona o jogador go1 a equipe q1

	q1.adicionarJogador(ap1);

	q1.adicionarJogador(ba1);

	q1.adicionarJogador(ap2);

	q1.adicionarJogador(ar1);

	q1.adicionarJogador(ar2);

	q1.adicionarJogador(ar3);



	q2.adicionarJogador(go2);

	q2.adicionarJogador(ap2);

	q2.adicionarJogador(ba4);

	q2.adicionarJogador(ba5);

	q2.adicionarJogador(ar4);

	q2.adicionarJogador(ar5);

	q2.adicionarJogador(ar6);//adiciona o jogador ar6 a equipe q2


	Partida p;
	string res;
	bool b;
	b = p.realizar(q1,q2,res);//realiza a partida entre q1 e q2, res é o resultado
	
	if (b)
		cout << q1.getNome() << " X " << q2.getNome() << " -> " << res << endl;

	else
		cout << "Jogo Inválido\n";

	q1.alterarJogador(3, ba2);//altera o jogador de índice 3 da equipe q1 para ba2

	b = p.realizar(q1,q2,res);
	if (b)
		cout << q1.getNome() << " X " << q2.getNome() << " -> " << res << endl;
	else
		cout << "Jogo Inválido\n";
}

