#include <iostream>
#include <cstring>

void inverse(char s[], int low, int high){
  if (high > strlen(s)) {
    return;
  }
  if (s[high] == ' ' || s[high] == '\0') {
    for (int i = high - 1; i >= low; i--) {
      std::cout << s[i];
    }
    if (s[high] == ' ') {
      std::cout << s[high];
      inverse(s, high + 1, high + 1);
    }
  } else {
    inverse(s, low, high + 1);
  }
}

int main(){
  char s[500] = {'\0'};
  std::cin.getline(s, 500);
  int length = strlen(s);
  inverse(s, 0, 0);
  return 0;
}
