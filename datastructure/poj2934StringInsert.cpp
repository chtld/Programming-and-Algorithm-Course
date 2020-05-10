#include<iostream>
#include<cstring>
#define MAXN (200000+2) 


using namespace std;
int find(char *p) {
	int index = 0;
	for (int i = 1; p[i] != '\0'; ++ i) {
		if (p[i] > p[index]) {
			index = i;
		}
	}
	return index;
}

void insert(char *str, char *substr, int index) {
	int length_substr = strlen(substr);
	int length_str = strlen(str);
	for (int i = length_str; i > index; --i) {
		str[i + length_substr] = str[i];
	}
	for (int i = 0; i < length_substr; ++ i) {
		str[index + i + 1] = substr[i];
	}
	return;
}

int main() {
	char str[MAXN], substr[MAXN];
	while (cin >> str >> substr) {
		int index = find(str);
		insert(str, substr, index);
		cout << str << endl;
	}
	return 0;
}