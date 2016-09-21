#include<iostream>

using namespace std;

int mdc(int a, int b){
	return b ? mdc(b, a%b) : a;
}


class NumeroRacional{
	private:
		int num, den;
	public:
		NumeroRacional(int num, int den){
			if(!den)
				throw -1;
			int m = mdc(num, den);
			num = num / m;
			den = den / m;

			if(den < 0){
				num = -num;
				den = -den;
			}

			this->num = num;
			this->den = den;
			cout << num << "/" << den << endl;
		}
		NumeroRacional operator+ (NumeroRacional ldo){//ldo - lado direito da operação
			return NumeroRacional(num*ldo.den+den*ldo.num, den*ldo.den);
		}
		NumeroRacional operator/ (NumeroRacional ldo){
			return NumeroRacional(num*ldo.den, den*ldo.num);
		}
		operator float(){
			return (float) num/den;
		}
		NumeroRacional& operator++(){//++a;
			num += den;
			return *this;
		}
		NumeroRacional operator++(int){//a++;
			NumeroRacional copia(*this);
			num += den;
			return copia;//retorna um valor local -> tem que ser por cópia, e não por referência
		}

		friend ostream& operator<< (ostream &os, const NumeroRacional &nr);
};

ostream& operator<< (ostream &os, const NumeroRacional &nr){//Tem que ser um método, pois o operador da esquerda(cout) não pertence a minha classe
	os << nr.num << "/" << nr.den << endl;
}

int main(){
	cout << mdc (30,21) << endl;
	NumeroRacional n1(4,12), n2(10, 15);
	NumeroRacional n3 = n1+n2;
	NumeroRacional n4 = n1/n2;
	float f = n3;
	cout << f << endl;
	cout << n3 << endl;
	
	return 0;
}
