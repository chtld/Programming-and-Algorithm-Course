#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;
// 在此处补充你的代码
class A{
public:
	int num;
	A(int k):num(k){};
	virtual void print() const{
		cout << "A" << " " << num <<endl;
	}
};
class B:public A{
public:
	B(int k):A(k){};
	virtual void print() const{
		cout << "B" << " " << num <<endl;
	}
};


struct Comp{
	bool operator()(const A * a, const A * b){
		return a->num < b->num;
	}
};
void Print(const A* p){
	p->print();
}

/* struct Print{
	void operator()(A* p){
		p->print();
	}
}; */
int main()
{

        int t;
        cin >> t;
        set<A*,Comp> ct;
        while( t -- ) {
                int n;
                cin >> n;
                ct.clear();
                for( int i = 0;i < n; ++i)	{
                        char c; int k;
                        cin >> c >> k;

                        if( c == 'A')
                                ct.insert(new A(k));
                        else
                                ct.insert(new B(k));
                }
                for_each(ct.begin(),ct.end(),Print);
                cout << "****" << endl;
        }
}