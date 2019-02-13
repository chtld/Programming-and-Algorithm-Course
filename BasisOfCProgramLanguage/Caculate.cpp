#include <iostream>

int main(){
  int a = 0, b = 0;
  char oper = '\0';
  std::cin >> a >> b >> oper;
  switch (oper) {
  case '+' :
    std::cout << a + b << std::endl;
    break;
  case '-' :
    std::cout << a - b << std::endl;
    break;
  case '*' :
    std::cout << a * b << std::endl;
    break;
  case '/' :
    if(b == 0) {
      std::cout << "Divided by zero!" << std::endl;
      break;
    }
    std::cout << a / b << std::endl;
    break;
  default:
    std::cout << "Invalid operator!" << std::endl;
  }
  return 0;
}
