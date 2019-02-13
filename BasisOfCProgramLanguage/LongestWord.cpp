#include <iostream>

int main(){
  char s[20] = {'\0'}, tmp[20] = {'\0'};
  int length = 0;
  while (std::cin >> s){
    int i = 0;
    bool flag = false;
    while (s[i] != '\0') {
      i++;
      if (s[i] == '.') {
        flag = true;
        s[i] = '\0';
        i--;
      }
    }
    if (i > length) {
      length = i;
      for (int j = 0; j < length; j++) {
        tmp[j] = s[j];
      }
      tmp[length] = '\0';
    }
    if (flag) {
      length = 0;
      std::cout << tmp << std::endl;
    }
  }
  return 0;
}
