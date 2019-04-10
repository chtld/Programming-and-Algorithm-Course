#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double temp = 0.0;
	cin >> temp;
	cout << fixed << setprecision(5) << temp << endl;
	cout << scientific << setprecision(7) << temp << endl;
	return 0;
}