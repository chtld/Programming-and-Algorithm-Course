#include <iostream>
#include <cstring>

using namespace std;

class CArray{
	int size;
	int *ptr;
	
	public:
	CArray(int s = 0);
	CArray(CArray &a);
	~CArray();
	void push_back(int v);
	int length() const {return size;};
	CArray & operator=(const CArray &a);
	int & operator[](int i){
		return ptr[i];
	}
};

CArray::CArray(int s):size(s){
	if(s == 0) ptr = nullptr;
	else ptr = new int[s];
}

CArray::CArray(CArray &a){
	if(!a.ptr) {
		ptr = nullptr;
		size = 0;
		return;
	}
	ptr = new int[a.size];
	memcpy(ptr, a.ptr, sizeof(int) * a.size);
	size = a.size;
}

CArray::~CArray(){
	if(!ptr) delete [] ptr;
}

void CArray::push_back(int v){
	if(ptr){
		int *temp = new int[size + 1];
		memcpy(temp, ptr, sizeof(int) * size);
		delete []ptr;
		ptr = temp;
	} else 
		ptr = new int[1];
	ptr[size++] = v;
}

CArray & CArray::operator=(const CArray &a){
	if(ptr == a.ptr) return *this;
	if(a.ptr == nullptr) {
		if (ptr) delete []ptr;
		ptr = nullptr;
		size = 0;
		return *this;
	}
	if(size < a.size){
		if (ptr) delete []ptr;
		ptr = new int[a.size];
	}
	memcpy(ptr, a.ptr, sizeof(int) * a.size);
	size = a.size;
	return *this;
}

int main(){
	CArray a;
	for (int i = 0; i < 5; ++i) {
		a.push_back(i);
	}
	CArray a2, a3;
	a2 = a;
	for (int i = 0; i < a.length(); ++i) {
		cout << a2[i] << ",";
	}
	a2 = a3;
	for (int i = 0; i < a2.length(); ++i) {
		cout << a2[i] << ",";
	}
	cout << endl;
	a[3] = 100;
	CArray a4(a);
	for (int i = 0; i < a4.length(); ++i) {
		cout << a4[i] << ",";
	}
	cout << endl;
	return 0;
}

