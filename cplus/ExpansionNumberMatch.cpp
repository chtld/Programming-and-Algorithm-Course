#include <iostream>
#include <cstring>

void match(char s[], int flag[], int n) {
  if (strlen(s) != n) {
    if (s[n] != ')') match(s, flag, n + 1);
    else {
      int i = n - 1;
      while (i >= 0 && (s[i] != '(' || flag[i] == 1)) i--;
      if (i != -1 && s[i] == '(' && flag[i] == 0) {
        flag[n] = 1;
        flag[i] = 1;
      }
      match(s, flag, n + 1);
    }
  }
}

int main() {
  char s[101] = {'\0'};
  while (std::cin.getline(s, 101)) {
    int flag[101] = {0};
    match(s, flag, 0);
    std::cout << s << std::endl;
    for (int i = 0; i < strlen(s); i++) {
      if (flag[i] == 0) {
        if (s[i] == '(') std::cout << "$";
        else if (s[i] == ')') std::cout << "?";
        else std::cout << " ";
      }
      else
        std::cout << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
