#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string multiply(string num1, string num2) {
	int len1 = num1.length();
	int len2 = num2.length();
	int len = len1 + len2 + 1;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	// tmp 储存每次乘法的结果，res储存最后相加的结果
	char res[len], tmp[len];
	for (int i = 0; i < len; ++ i) {
		res[i] = '0';
		tmp[i] = '0';
	}
	for (int i = 0; i < len1; ++ i) {
		int jw = 0, r_jw = 0;
		for (int j = 0; j < len2; ++ j) {
			tmp[j] = ((num1[i] - '0') * (num2[j] - '0') + jw) % 10 + '0';
			jw = ((num1[i] - '0') * (num2[j] - '0') + jw) / 10;
			int res_tmp = (res[i + j] - '0') + (tmp[j] - '0') + r_jw;
			res[i + j] = res_tmp % 10 + '0';
			r_jw = res_tmp / 10;
		}
		if (r_jw != 0 || jw != 0) {
			res[len2 + i] = jw + r_jw + '0';
		}
	}
	string result = "";
	bool flag = false;
	for (int i = len - 1; i >= 0; --i) {
		if (res[i] != '0' && !flag) {
			result += res[i];
			flag = true;
		} else if (flag) {
			result += res[i];
		}
	}
	if (result == "") result = "0";
	return result;
}

int main() {
	string num1, num2;
	cin >> num1 >> num2;
	string result = multiply(num1, num2);
	cout << result << endl;
	return 0;
}