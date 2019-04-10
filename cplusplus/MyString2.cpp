#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char * s) 
{	int i = 0;
	for(; s[i]; ++i);
	return i;
}
void strcpy(char * d,const char * s)
{
	int i = 0;
	for( i = 0; s[i]; ++i)
		d[i] = s[i];
	d[i] = 0;
		
}
int strcmp(const char * s1,const char * s2)
{
	for(int i = 0; s1[i] && s2[i] ; ++i) {
		if( s1[i] < s2[i] )
			return -1;
		else if( s1[i] > s2[i])
			return 1;
	}
	return 0;
}
void strcat(char * d,const char * s)
{
	int len = strlen(d);
	strcpy(d+len,s);
}
class MyString
{
// 在此处补充你的代码
	char *p;
public:
	MyString(const char *s) {
		if(s == NULL) p = NULL;
		else {
			p = new char[strlen(s) + 1];
			strcpy(p, s);
		}
	}
	MyString(const MyString & temp){
		if (temp.p == NULL) p = NULL;
		else {
			p = new char[strlen(temp.p) + 1];
			strcpy(p, temp.p);
		}
	}
	MyString(){p = NULL;};
	~MyString(){if(p) delete []p;};
	friend ostream & operator << (ostream & os, const MyString & temp){
		if(temp.p) os << temp.p;
		return os;
	}
	MyString & operator=(const MyString & temp){
		if (p == temp.p) return *this;
		if (temp.p == NULL) p = NULL;
		else {
			if(p) delete []p;
			p = new char[strlen(temp.p) + 1];
			strcpy(p, temp.p);
		}
		return *this;
	}
	MyString operator+(const MyString & temp){
		char *s;
		s = new char[strlen(p) + strlen(temp.p) + 1];
		s[0] = '\0';
		strcat(s, p);
		strcat(s + strlen(p), temp.p);
		MyString ret(s);
		return ret;
	}
	char & operator[](int i){
		return p[i];
	}
	MyString & operator=(const char *s){
		if (p == s) return *this;
		if (p) delete []p;
		if(s == NULL) {	
			p = NULL;
		} else {
			p = new char[strlen(s) + 1];
			strcpy(p, s);
		}
		return *this;
	}
	MyString & operator+=(const MyString &temp){
		(*this) = (*this) + temp;
		return *this;
	}
	MyString operator+(const char *s){
		MyString temp2(s);
		return (*this + temp2);
	}
	friend MyString operator+(const char *s, const  MyString &temp2){
		MyString temp1(s);
		return (temp1 + temp2);
	}
	MyString operator()(int i, int j){
		char *s = new char[j + 1];
		for (int k = 0; k < j; k++) {
			s[k] = p[k + i]; 
		}
		s[j] = '\0';
		return MyString(s);
	}
	bool operator<(const MyString &temp2){
		int flag = strcmp(p, temp2.p);
		if(flag < 0) return true;
		else return false;
	}
	bool operator>(const MyString &temp2){
		int flag = strcmp(p, temp2.p);
		if(flag > 0) return true;
		else return false;
	}
	bool operator==(const MyString &temp2){
		int flag = strcmp(p, temp2.p);
		if(flag == 0) return true;
		else return false;
	}
};


int CompareString( const void * e1, const void * e2)
{
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
	return -1;
	else if( *s1 == *s2)
	return 0;
	else if( *s1 > *s2 )
	return 1;
}
int main()
{
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0,4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5,10) << endl;
	return 0;
}