#include <iostream>

int main(){
  int date = 0;
  std::cin >> date;
  if(date <= 5 && date%2 == 1){
    std::cout << "NO";
  } else {
    std::cout << "YES";
  }
  return 0;
}
