#include<iostream>
using namespace std;

class location{
	private:
	int x, y;
	
	public:
	void init(int X = 0, int Y = 0);
	void valueX(int X){
		x = X;
	}
	int valueX(){
		return x;
	}
};

void location::init(int X, int Y){
	x = X;
	y = Y;
}

int main(){
	location A;
	A.init(5);
	A.valueX(3);
	cout << A.valueX() << endl; 
	return 0;
}