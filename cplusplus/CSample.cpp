#include <iostream>
using namespace std;

class CSample{
	int x;
	
	public:
	CSample(){
		cout << "Constructor 1 called!" << endl;
	}
	CSample(int n){
		x = n;
		cout << "Constructor 2 called!" << endl;
	}
};

int main(){
	CSample array1[2];
	cout << "step 1" << endl;
	CSample array2[2] = {4, 5};
	cout << "step 2" << endl;
	CSample array3[2] = {3};
	cout << "step 3" << endl;
	CSample *array4 = new CSample[2];
	delete []array4;
	return 0;
}