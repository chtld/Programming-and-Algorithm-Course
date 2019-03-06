#include <iostream>
using namespace std;

class Complex{
	double real, imag;
	public:
	Complex(double r = 0.0, double i = 0.0):real(r), imag(i) { };
	Complex operator-(const Complex &c);
	Complex operator+(const Complex &c);
	friend Complex operator-(double r, const Complex &c);
	friend Complex operator+(double r, const Complex &c);
	void print();
};


Complex Complex::operator-(const Complex &c){
	return Complex(real - c.real, imag - c.imag);
}

Complex Complex::operator+(const Complex &b){
	return Complex(real + b.real, imag + b.imag);
}

Complex operator-(double r, const Complex &c){
	return Complex(r - c.real, -c.imag);
}

Complex operator+(double r, const Complex &c){
	return Complex(r + c.real, c.imag);
}

void Complex::print(){
	cout << real << "," << imag << endl;
}

int main(){
	Complex a(4, 4), b(1, 1), c, d;
	c = a + b;
	d = a - c;
	c.print();
	(a - b).print();
	(5 - a).print();
	(5 + a).print();
	return 0;
}