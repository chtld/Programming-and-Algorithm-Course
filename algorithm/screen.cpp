#include <iostream>

using namespace std;

int main(){
	int s = 0;
	char num[11];
	char n1[11] = {"- -- -----"};
	char n2[11] = {"|   ||| ||"};
	char n3[11] = {"|||||  |||"};
	char n4[11] = {"  ----- --"};
	char n5[11] = {"| |   | | "};
	char n6[11] = {"|| |||||||"};
	char n7[11] = {"- -- -- --"};
	while (true) {
		cin >> s >> num;
		if (s == 0 && num[0] == '\0') 
			break;
		for (int i = 0; num[i] != '\0'; ++ i) {
			cout << " ";
			for (int j = 0; j < s; ++ j)
				cout << n1[num[i] - '0'];
			cout << " ";
			cout << " ";
		}
		cout << endl;
		for (int i = 0; i < s; ++ i) {
			for (int j = 0; num[j] != '\0'; ++ j) {
				cout << n2[num[j] - '0'];
				for (int k = 0; k < s; ++ k) {
					cout << " ";
				}
				cout << n3[num[j] - '0'];
				cout << " ";
			}
			cout << endl;
		}
		for (int i = 0; num[i] != '\0'; ++ i) {
			cout << " ";
			for (int j = 0; j < s; ++ j)
				cout << n4[num[i] - '0'];
			cout << " ";
			cout << " ";
		}
		cout << endl;
		for (int i = 0; i < s; ++ i) {
			for (int j = 0; num[j] != '\0'; ++ j) {
				cout << n5[num[j] - '0'];
				for (int k = 0; k < s; ++ k) {
					cout << " ";
				}
				cout << n6[num[j] - '0'];
				cout << " ";
			}
			cout << endl;
		}
		for (int i = 0; num[i] != '\0'; ++ i) {
			cout << " ";
			for (int j = 0; j < s; ++ j)
				cout << n7[num[i] - '0'];
			cout << " ";
			cout << " ";
		}
	}
	return 0;
}