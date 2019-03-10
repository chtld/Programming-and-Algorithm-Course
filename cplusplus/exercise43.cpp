#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
// 在此处补充你的代码
private:
    int row, column; 
	int *a;
public:
	Array2():row(0), column(0), a(nullptr) {}
	Array2(int m, int n):row(m), column(n){
		a = new int[m*n];
	}
	~Array2(){
		if(a) delete []a;
	}
	int * operator[](int i){
		return (a + i*column);
	}
	int & operator()(int i, int j){
		return a[column * i + j];
	}
	Array2& operator=(const Array2& p){
		if(p.a == nullptr){
			if(a) delete []a;
			a = nullptr;
			row = p.row;
			column = p.column;
			return *this;
		}
		if(a) delete []a;
		row = p.row;
		column = p.column;
		a = new int[row * column];
		memcpy(a, p.a, sizeof(int) * row * column);
		return *this;
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