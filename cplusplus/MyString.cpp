#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString {
	char * p;
public:
	MyString(const char * s) {
		if( s) {
			p = new char[strlen(s) + 1];
			strcpy(p,s);
		}
		else
			p = NULL;

	}
	~MyString() { if(p) delete [] p; }
// 在此处补充你的代码
	MyString(const MyString & temp) {
		if (temp.p == NULL) p = NULL;
		else {
			p = new char[strlen(temp.p)];
			strcpy(p, temp.p);
		}
	}
	MyString & operator = (const char *s){
		if (s == NULL) {
			if (p) delete []p;
			p = NULL;
			return *this;
		}
		if (p) delete []p;
		p = new char[strlen(s) + 1];
		strcpy(p, s);
		return *this;
	}
	MyString & operator = (const MyString & temp) {
		if (p == temp.p) return *this;
		if (temp.p == NULL) {
			if (p) delete []p;
			p = NULL;
			return *this;
		}
		if (p == NULL || strlen(p) < strlen(temp.p)) {
			if (p) delete []p;
			p = new char[strlen(temp.p) + 1];
		}
		strcpy(p, temp.p);
		return *this;
	}
	void Copy (const char *s){
		if (s == NULL) {
			if (p) delete []p;
			p = NULL;
			return;
		}
		if (p == NULL || strlen(p) < strlen(s)) {
			if (p) delete []p;
			p = new char[strlen(s) + 1];
		}
		strcpy(p, s);
		return;
	}
	friend ostream & operator << (ostream & os, const MyString & temp){
		os << temp.p;
		return os;
	}
};
int main()
{
	char w1[200],w2[100];
	while( cin >> w1 >> w2) {
		MyString s1(w1),s2 = s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

		s2 = w2;
		s3 = s2;
		s1 = s3;
		cout << s1 << "," << s2 << "," << s3 << endl;
		
	}
}