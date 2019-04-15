#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int Getnum(int a) {
	int count = 0;
	for (int i = 2; i <= sqrt(a); ++ i) {
		bool flag = true;
		while (a % i == 0) {
			if (flag) count++;
			a = a / i;
			flag = false;
		}
	}
	if (a > 1 && count != 0) count++;
	return count;
}
struct cmp1{
	bool operator()(int a, int b){
		int numa = Getnum(a);
		int numb = Getnum(b);
		if (numa < numb) {
			return true;
		} else if (numa == numb) {
			return a < b;
		} else {
			return false;
		}
	}

};

struct cmp2{
	bool operator()(int a, int b){
		int numa = Getnum(a);
		int numb = Getnum(b);
		if (numa < numb) {
			return false;
		} else if (numa == numb) {
			return a > b;
		} else {
			return true;
		}
	}

};

int main(){
	int num = 0;
	cin >> num;		
	priority_queue<int, vector<int>, cmp1> pq1;
	priority_queue<int, vector<int>, cmp2> pq2;
	for (int i = 0; i < num; ++ i) {
		int n;
		for (int j = 0; j < 10; ++ j) {
			cin >> n;
			pq1.push(n);
			pq2.push(n);
		}
		cout << pq1.top() << " " << pq2.top() << endl;
		pq1.pop();
		pq2.pop();
	}
	return 0;
}