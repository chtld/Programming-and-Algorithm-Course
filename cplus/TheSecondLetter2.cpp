#include <iostream>
#include <algorithm>
using namespace std;

struct letterNum{
  char ch;
  int count;
};

bool compare(letterNum &a, letterNum &b){
  return a.count > b.count;
}


int main(){
  struct letterNum s[501]; 
  char a[501];
  cin >> a;
  int k = 0;
  for (int i = 0; a[i] != '\0'; i++) {
	if (a[i] >= 'a' && a[i] <= 'z') {
	  a[i] -= 32;
	}
	if (a[i] >= 'A' && a[i] <= 'Z') {
	  bool found = false;
	  for (int j = 0; j < k; j++) {
		if (a[i] == s[j].ch) {
			s[j].count++;
			found = true;
		}
	  }
	  if (!found) {
		s[k].ch = a[i];
		s[k].count = 1;
		k++;
	  }
	}
  }
  
  letterNum first = s[0], second = s[0];
  for (int i = 1; i < k; i ++) {
	  if (s[i].count < first.count) {
		second = s[i];
		break;
	  }
  }
  // sort(s, &s[k], compare);
  for (int i = 1; i < k; i++) {
	if (s[i].count > first.count) {
		second = first;
		first = s[i];
	} else if (s[i].count < first.count && s[i].count > second.count) {
		second = s[i];
	}	 
  }
   cout << second.ch << "+" << (char)(second.ch + 32) << ":" << second.count << endl;
  return 0;
}