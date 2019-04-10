#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int temp;
	cin >> temp;
	cout << hex << temp << endl;
	cout << dec << setw(10) << setfill('0') << temp << endl;
	return 0;
}