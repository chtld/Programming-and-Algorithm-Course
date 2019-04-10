#include <iostream>
#include <cstring>

using namespace std;

class String{
	private:
	char *str;
	
	public:
	String ():str(nullptr) {}
	String (const String &s);
	String (const char *s);
	const char *c_str() const {return str;}
	String &operator=(const char *s);
	String &operator=(const String &s);
	~String();
};

String::String(const String &s){
	if(s.str){
		str = new char[strlen(s.str) + 1];
		strcpy(str, s.str);
	} else 
		str = nullptr;
}

String::String(const char *s){
	if(s){
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	} else
		str = nullptr;
}

String & String::operator=(const char *s){
	if(str) delete []str;
	if(s){
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	} else
		str = nullptr;
	return *this;
}

String & String::operator=(const String &s){
	if(str == s.str){
		return *this;
	}
	if(str) delete []str;
	if(s.str){
		str = new char[strlen(s.str) + 1];
		strcpy(str, s.str);
	} else 
		str = nullptr;
	return *this;
}

String::~String(){
	if(str) delete []str;
}

int main(){
	String s;
	s = "Good luck!";
	cout << s.c_str() << endl;
	String s2 = "Hello!";
	cout << s2.c_str() << endl;
	s = "Shenzhou8!";
	cout << s.c_str() << endl;
	return 0;
}