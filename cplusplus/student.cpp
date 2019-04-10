#include <iostream>
#include <cstdio>
using namespace std;

class student{
	private:
	char name[20];
	unsigned int age;
	char id[20];
	int first, second, third, fourth, average;

	public:
	void init();
	void print();
	void makeaverage();
};

void student::makeaverage(){
	average = (first + second + third + fourth) / 4;
}

void student::print(){
	cout << name << "," << age << "," << id << "," << average << endl;
}

void student::init(){
	cin.get(name, 20, ',');
	char k;
	cin >> k >> age >> k;
	cin.get(id, 20, ',');
	cin >> k >> first >> k >> second >> k >> third >> k >> fourth;
}

int main(){
	student a;
	a.init();
	a.makeaverage();
	a.print();
	return 0;
}