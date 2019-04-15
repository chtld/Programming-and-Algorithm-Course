class A{
public:
	int num;
	static int count;
	A(){
		A::count++;
	}
	A(int k):num(k){
		A::count++;
	}
	A(A& a){
		A::count++;
		num = a.num;
	}
	virtual ~A(){
		A::count--;
		cout << "A::destructor" << endl;
	}
};
class B:public A{
public:
	B():A(){}
	B(int k):A(k){}
	virtual ~B(){
		cout  << "B::destructor" << endl;
	}
};