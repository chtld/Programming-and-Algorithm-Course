#include <iostream>

int main(){
  char s[80] = {'\0'};
  int a[5] = {0};
  std::cin.getline(s,80);
  for (int i = 0; s[i] != '\0'; i++) {
    switch (s[i]) {
    case 'a' :
      a[0]++;
      break;
    case 'e' :
      a[1]++;
      break;
    case 'i' :
      a[2]++;
      break;
    case 'o' :
      a[3]++;
      break;
    case 'u' :
      a[4]++;
      break;
    }
  }
  for (int i = 0; i < 5; i++) {
    std::cout << a[i] << " ";
  }
  return 0;
}
