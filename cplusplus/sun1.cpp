#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	n = 1024-n;
	int count = 0;
	switch(64){
		case 64:
			count = count + n/64;
			n = n - (n/64)*64;
		case 16:
			count = count + n/16;
			n = n - (n/16)*16;
		case 4:
			count = count + n/4;
			n = n - (n/4)*4;
		case 1:
			count = count + n/1;
			n = n - (n/1)*1;
	}
	cout << count << endl;
	return 0;
}