#include <iostream>

using namespace std;

char leftq[3][7], rightq[3][7], result[3][5];
int status[12] = {0};

bool Balance() {
	int leftv = 0, rightv = 0;
	for (int i = 0; i < 3; ++ i) {
		leftv = 0;
		rightv = 0;
		for (int j = 0; leftq[i][j] != '\0' && rightq[i][j] != '\0'; ++ j) {
			leftv += status[leftq[i][j] - 'A'];
			rightv += status[rightq[i][j] - 'A'];
		}
		if (leftv == rightv && result[i][0] != 'e') return false;
		if (leftv > rightv && result[i][0] != 'u') return false;
		if (leftv < rightv && result[i][0] != 'd') return false;
	}
	return true;
}


int main(){
	int n = 0;
	cin >> n;
	while (n--) {
		for (int i = 0; i < 3; ++ i) {
			scanf("%s %s %s", leftq[i], rightq[i], result[i]);
		}
		for (int i = 0; i < 12; ++ i) {
			status[i] = 0;
		}
		int i = 0;
		for (; i < 12; ++ i) {
			status[i] = 1;
			if (Balance()) break;
			status[i] = -1;
			if (Balance()) break;
			status[i] = 0;
		}
		cout << char('A' + i) << " is the counterfeit coin and it is " 
			 << (status[i] > 0 ? "heavy." : "light.") << endl;
	}
	return 0;
}