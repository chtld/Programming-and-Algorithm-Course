#include <iostream>
using namespace std;
// 在此处补充你的代码
class  CType{
public:
	int num;
	CType(){}
	CType(int n):num(n){}
	void setvalue(int n){
		num = n;
	}
	CType operator++(int){
		int temp = num;
		num = num * num;
		return CType(temp);
	}
	friend ostream& operator<<(ostream& os, CType temp);
};
ostream& operator <<(ostream& os, const CType temp){
	os << temp.num;
	return os;
}


int main(int argc, char* argv[]) {
        CType obj;
        int n;
        cin>>n;
        while ( n ) {
                obj.setvalue(n);
                cout<<obj++<<" "<<obj<<endl;
                cin>>n;
        }
        return 0;
}