#include<iostream>
#include<math.h>

using namespace std;

class Complexo{
	private:
		double real, imaginario;
	public:
		Complexo(double x, double y){
			real = x;
			imaginario = y;
		}
		Complexo (){
			real = 0;
			imaginario = 0;
		}
		double getReal(){
			return real;
		}
		double getImaginario(){
			return imaginario;
		}
		void setReal(double r){
			real = r;
		}
		void setImaginario (double r){
			imaginario = r;
		}
		Complexo soma(Complexo c2){
			Complexo r;
			r.real = real + c2.real;
			r.imaginario = imaginario + c2.imaginario;
			return r;
		}
		Complexo diferenca(Complexo c2){
			Complexo r;
			r.real = real - c2.real;
			r.imaginario = imaginario - c2.imaginario;
			return r;
		}
		Complexo mult(Complexo c2){
			Complexo r;
			r.real = real*c2.real - imaginario*c2.imaginario;
			r.imaginario = real*c2.imaginario + imaginario*c2.real;
			return r;
		}
		Complexo divisao(Complexo c2){
			Complexo r;
			r.real = (real*c2.real + imaginario*c2.imaginario)/(c2.modulo()*c2.modulo());
			r.imaginario = (imaginario*c2.real - real*c2.imaginario)/(c2.modulo()*c2.modulo());
			return r;
		}
		Complexo conjugado(){
			Complexo r;
			r.real = real;
			r.imaginario = -imaginario;
			return r;
		}
		double modulo(){
			double mod;
			mod = (real*real + imaginario*imaginario);
			mod = sqrt(mod);
			return mod;
		}
		void imprimir(){
			cout << real << "+(" << imaginario << ")i" << endl;
		}
};

int main(){
	Complexo c1, c2;
	c1.setReal(1.0);
	c2.setReal(2.0);
	c1.setImaginario(10.0);
	c2.setImaginario(20.0);
	Complexo b = c1.diferenca(c2);
	Complexo c = c1.soma(c2);
	Complexo d = c1.mult(c2);
	Complexo e = c1.conjugado();
	Complexo f = c1.divisao(c2);
	double mod = c1.modulo();
	cout << "Soma: " << c.getReal() << "+" << c.getImaginario() <<"i" << endl;
	cout << "Diferença: " << b.getReal() << "+(" << b.getImaginario() <<")i" << endl;
	cout << "Multiplicacao: " << d.getReal() << "+" << d.getImaginario() <<"i" << endl;
	cout << "Divisao: " << f.getReal() << "+" << f.getImaginario() <<"i" << endl;
	cout << "Conjugado: " << e.getReal() << "+(" << e.getImaginario() << ")i" << endl;
	c1.imprimir();
	cout << "Modulo: " << mod << endl;
	return 0;
}
