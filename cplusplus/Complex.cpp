#include <iostream>
using namespace std;

class Complex{
	private:
	double real, imag;
	public:
	void Set(double r, double i);
	Complex(double r, double i);
	Complex(double r);
	Complex(Complex c1, Complex c2);
};

Complex::Complex(double r, double i){
	real = r;
	imag = i;
}

Complex::Complex(double r){
	real = r;
	imag = 0;
}

Complex::Complex(Complex c1, Complex c2){
	real = c1.real + c2.real;
	imag = c1.imag + c2.imag;
}


int main(){
	Complex c1(2);
	Complex c2(3, 5);
	Complex *pc = new Complex(3, 4);
	Complex c3(c1, c2);
	return 0;
}