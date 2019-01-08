#include <iostream>

int main(){
  int score = 0;
  std::cin >> score;
  if(score < 60)
    std::cout << 7 << std::endl;
  else if(score < 70)
    std::cout << 6 << std::endl;
  else if(score < 80)
    std::cout << 5 << std::endl;
  else if(score < 85)
    std::cout << 4 << std::endl;
  else if(score < 90)
    std::cout << 3 << std::endl;
  else if(score < 95)
    std::cout << 2 << std::endl;
  else if(score <= 100)
    std::cout << 1 << std::endl;
  else
    std::cout << "this is a error!" << std::endl;
  return 0;
}
