#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
// 在此处补充你的代码
    int row, column; 
	private:
	int *a;
	Array2(int m, int n):row(m), column(n){
		a = new int[m*n];
	}
	~Array2(){
		if(a) delete []a;
	}
	Array2 & operator[]{
		
	}
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}