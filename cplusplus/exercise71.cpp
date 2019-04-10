#include <iostream>
using namespace std;
// 在此处补充你的代码
template<class T>
class CArray3D{
private:
	T ***array;
	int r, c, l;
	
public:
	CArray3D(){array = NULL;}
	CArray3D (int _r, int _c, int _l) {
		r = _r;
		c = _c;
		l = _l;
		array = new T**[r];
		for (int i = 0; i < r; ++ i) {
			array[i] = new T*[c];
			for (int j = 0; j < c; ++ j) {
				array[i][j] = new T[l];
			}
		}
	}
	~CArray3D(){
		for (int i = 0; i < r; ++ i) {
			for (int j = 0; j < c; ++ j) {
				delete []array[i][j];
			}
			delete []array[i];
		}
		delete []array;
	}
	T ** operator[](int index){
		return array[index];
	}
};
int main()
{
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
return 0;
}
