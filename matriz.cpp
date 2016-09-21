//MATRIZ
#include<iostream>

using namespace std;

class Matriz{
	private:
		double a1, a2, a3, a4;
	public:
		Matriz();
		Matriz(double, double, double, double);
		void visualizar(){
			cout << a1 << "   " << a2 << endl;
			cout << a3 << "   " << a4 << endl;
		}
		double determinante();
		Matriz inversa();
		Matriz mult(Matriz);
		void atributos(double, double, double, double);
};

Matriz::Matriz(){
	a1 = a2 = a3 = a4 = 0;
}

Matriz::Matriz(double a, double b, double c, double d){
	a1=a;
	a2=b;
	a3=c;
	a4=d;
}

double Matriz::determinante(){ return a1*a4 - a2*a3; }

Matriz Matriz::inversa(){
	Matriz A;
	if(determinante() == 0){
		cout << "Não há determinante" << endl;
	}
	else {
		A.a1 =  a4/determinante();
		A.a2 = -a2/determinante();
		A.a3 = -a3/determinante();
		A.a4 =  a1/determinante();
	}
	return A;
}

Matriz Matriz::mult(Matriz M){
	Matriz R;
	R.a1 = a1*M.a1 + a2*M.a3;
	R.a2 = a1*M.a2 + a2*M.a4;
	R.a3 = a3*M.a1 + a4*M.a3;
	R.a4 = a3*M.a2 + a4*M.a4;
	return R;
}

void Matriz::atributos(double a, double b, double c, double d){
	a1=a;
	a2=b;
	a3=c;
	a4=d;
}

int main(){
	Matriz A;
	Matriz B(1, 2, 3, 4);
	Matriz C = B.inversa();
	Matriz D = B.mult(C);
	double det = B.determinante();
	A.visualizar();
	cout << endl;
	B.visualizar();
	cout << "Determinante: " << det << endl;
	C.visualizar();
	D.visualizar();
	return 0;}
