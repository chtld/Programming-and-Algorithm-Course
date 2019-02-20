#include<iostream>

char pair(char a) {
  switch (a){
  case 'A': return 'T';
  case 'T': return 'A';
  case 'G': return 'C';
  case 'C': return 'G';
  default: return '\0';
  }
}

int main(){
  int n = 0;
  std::cin >> n;
  char str[256] = {'\0'};
  for (int i = 0; i < n; i++) {
    std::cin >> str;
    for (int j = 0; str[j] != '\0'; j++) {
      str[j] = pair(str[j]);
    }
    std::cout << str << std::endl;
  }
  return 0;
}
