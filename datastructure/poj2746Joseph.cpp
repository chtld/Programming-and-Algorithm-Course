#include<iostream>
#include<cstdio>

using namespace std;

template<typename T>
class Vector{
	private:
		T *_elem;
		int maxSize;
		int curSize;
	public:
		Vector(const int size) {
			maxSize = size;
			_elem = new T[size];
			curSize = 0;
		}
		~Vector(){
			delete []_elem;
		}
		T & operator[] (int index) {
			return _elem[index];
		}
		void add(const T num) {
			_elem[curSize] = num;
			curSize++;
		}
		void remove(int index){
			for (int i = index; i < curSize - 1; ++ i) {
				_elem[i] = _elem[i + 1];
			}
			curSize--;
		}
		int size(){
			return curSize;
		}
};


int main(){
	int n, m;
	cin >> n >> m;
	Vector<int> a(n);
	for (int i = 1; i <= n; ++ i) {
		a.add(i);
	}
	int cur = 0;
	while (a.size() != 1) {
		for (int i = 0; i < m - 1; ++ i) {
			cur++;
			if (cur == a.size())
				cur = 0;
		}
		a.remove(cur);
		if (cur == a.size())
			cur = 0;
	}
	cout << a[0] << endl;
	return 0;
}