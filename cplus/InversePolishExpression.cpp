#include <iostream>

double notation(){
  char str[10];
  std::cin >> str;
  switch (str[0]){
  case '+': return notation() + notation();
  case '-': return notation() - notation();
  case '*': return notation() * notation();
  case '/': return notation() / notation();
  default: return atof(str);
  }
}

int main(){
  std::cout << notation();
  return 0;
}
