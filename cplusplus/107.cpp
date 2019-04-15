bool operator < (const class A& a1, const class A &a2){
	return a1.name.size() < a2.name.size();
}
template<class T>
struct MyLarge{
	bool operator()(const T & a1, const T & a2){
		return a1.get_name()[0] < a2.get_name()[0];
	}
};

struct Print{
	void operator()(const A& a){
		cout << a << " ";
	}
};

void Show(list<A>::iterator begin, list<A>::iterator end, Print print) {
	for (list<A>::iterator i = begin; i != end; ++ i) {
		print(*i);
	}
}