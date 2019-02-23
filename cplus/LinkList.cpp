#include<iostream>
using namespace std;

struct student{
	int id;
	student *next;
};

student *creat();
void print(student *head);
student *deletenode(student *head, int n);
student *insert(student *head, int n);
int main () {
	student *pointer = creat();
	print(pointer);
	pointer = deletenode(pointer, 3);
	print(pointer);
	return 0;
}


student *creat(){
	student *head = new student;
	student *temp = head;
	int n = 0;
	cin >> n;
	temp->id = 2013000;
	for (int i = 1; i < n; i++) {	
		temp->next = new student;
		temp = temp->next;
		temp->id = 2013000 + i;
	}
	temp->next = nullptr;
	return head;
}

void print(student *head){
	while(head) {
		cout << head->id << endl;
		head = head->next;
	}
}

student *deletenode(student *head, int n){
	student *temp, *follow;
	temp = head;
	if (head == nullptr){
		return head;
	}
	if (head->id == n){
		head = head->next;
		delete temp;
		return head;
	}
	while(temp && temp->id != n) {
		follow = temp;
		temp = temp->next;
	}
	if (temp == nullptr) cout << "not found";
	else {
		follow->next = temp->next;
		delete temp;
	}
	return head;
}

student *insert(student *head, int n){
	student *temp, *unit, *follow;
	temp = head;
	unit = new student;
	unit->id = n;
	unit->next = nullptr;
	if (head == nullptr){
		head = unit;
		return head;
	}
	while(temp->next != nullptr && temp->id < n){
		follow = temp;
		temp = temp->next;
	}
	if (temp == head){
		unit->next = head;
		head = unit;
	} else {
		if (temp->next == nullptr) temp->next = unit;
		else{
			follow->next = unit;
			unit->next = temp;
		}
	}
	return head;
}