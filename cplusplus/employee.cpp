#include <iostream>
#include <cstring>
using namespace std;

class employee{
	private:
	char name[30];
	public:
	int salary;
	void setName(const char *name_);
	void getName(char *name_);
	void average(employee e1, employee e2);
};

void employee::setName(const char *name_){
	strcpy(name, name_);
}

void employee::getName(char *name_){
	strcpy(name_, name);
}

void employee::average(employee e1, employee e2){
	salary = (e1.salary + e2.salary)/2;
}

int main(){
	employee e;
	e.setName("Tom");
	e.salary = 500;
	return 0;
}