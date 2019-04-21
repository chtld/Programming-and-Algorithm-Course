#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
	int n;
	cin >> n;
	while (n--) {
		double a, b, c;
		cin >> a >> b >> c;
		double delta = b*b - 4*a*c;
		if (delta > 0) { 
			double root1 = (-b + sqrt(delta)) / (2 * a);
			double root2 = (-b - sqrt(delta)) / (2 * a);
			cout << fixed << setprecision(5) << "x1 = " << root1 << ";" << "x2 = " << root2 << endl;
		} else if (delta == 0) {
			double root = -b / (2 * a);
			cout << fixed << setprecision(5) << "x1 = x2 = " << root << endl;
		} else {
			double real1 = (-b) / (2 * a);
			double imag1 = (sqrt(-delta)) / (2 * a);
			double real2 = (-b) / (2 * a);
			double imag2 = -(sqrt(-delta)) / (2 * a);
			cout << fixed << setprecision(5) << "x1 = " << real1 << "+" << imag1 << "i" << ";" << "x2 = " << real2 << imag2 << "i" << endl;
		}
	}
	return 0;
}