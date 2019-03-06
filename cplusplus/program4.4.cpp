#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

class Complex{
	double real, imag;
	public:
	Complex(double r = 0, double i = 0):real(r), imag(i) {}
	friend ostream & operator<<(ostream & os, const Complex &c);
	friend istream & operator>>(istream & is, Complex &c);
};

ostream & operator<<(ostream & os, const Complex &c){
	os << c.real << "+" << c.imag << "i";
	return os;
}

istream & operator>>(istream & is, Complex &c){
	string s;
	is >> s;
	int pos = s.find("+", 0);
	string stmp = s.substr(0, pos);
	c.real = atof(stmp.c_str());
	stmp = s.substr(pos + 1, s.length() - pos - 2);
	c.imag = atof(stmp.c_str());
	return is;
}

int main(){
	Complex c;
	int n;
	cin >> c >> n;
	cout << c << "," <<n;
	return 0;
}