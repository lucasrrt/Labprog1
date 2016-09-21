#include<iostream>
#include<sstream>

using namespace std;

class AcessoInvalido{
	public:
		string linha;
		string msg;
		AcessoInvalido(string linha, int i, int qtd){
			this->linha = linha;
			ostringstream os;
			os << "Indice passado: "<< i << "eh maior que " << qtd-1;
			msg = os.str();
		}
};
template <class T>
class Conjunto{
	private:
		int qtd, tamanho;
		T *elems;
	public:
		Conjunto(int tamanho):qtd(0), tamanho(tamanho){
			elems = new T[tamanho];
		}
		~Conjunto(){
			delete[] elems;
		}
		Conjunto& operator+=(Conjunto &ldo){
			for(int i = 0; i<ldo.qtd;i++)
				*this += ldo.elems[i];
			return *this;
		}
		Conjunto& operator+=(T elem){
			if(qtd==tamanho)
				return *this;
			for(int i = 0; i<qtd;i++)
				if(elems[i] == elem)
					return *this;
			elems[qtd++] = elem;
			return *this;
		}
		Conjunto& operator-=(Conjunto &ldo){
			for(int i = 0; i<ldo.qtd;i++)
				*this -= ldo.elems[i];
			return *this;
		}
		Conjunto& operator-=(T elem){
			for(int i = 0; i<qtd;i++){
				if(elems[i]==elem){
					elems[i]=elems[--qtd];
					break;
				}
			}
			return *this;
		}
		Conjunto& operator*=(Conjunto&ldo){
			int i,j;
			for(i = qtd-1; i>=0; i--){
				for(j = 0;j<ldo.qtd;j++)
					if(elems[i]==ldo.elems[j])
						break;
				if(j==ldo.qtd)
					this -=elems[i];
			}
		}
		void operator!(){
			for(int i = 0; i< qtd; i++)
				cout << elems[i] << " ";
			cout << endl;
		}
		operator int(){
			return qtd;
		}
		T operator[](int i){
			if(i<qtd)
				return elems[i];
			throw AcessoInvalido("return elems[i]", i, qtd);
		}
};

int main(){
	Conjunto <int> c1(10);
	Conjunto<char> c2(20);
	Conjunto <int> c3(20);
	Conjunto <int> c4(10);

	c1+=3;
	c1+=5;

	c3+=7;
	c3+=9;

	!c1;
	!c3;

	c1+=c3;
	!c1;

	c1-=5;

	!c1;

	c4+=3;
	c4+=7;

	c1-=c4;

	!c1;

	Conjunto<int> c5(5);
	cout << (c1<1) << endl;
	cout << (c5<1) << endl;

	cout << c1[1] << endl;
	try{
		cout << c1[13000];
	}
	catch(AcessoInvalido ai){
		cout << "Ocorreu um erro na linha "<< ai.linha << endl << "Mensagem de erro: " << ai.msg << endl;
	}
	return 0;
}
