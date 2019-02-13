#include <iostream>

int main(){
  for (int best = 1; best < 5; best++){
    bool a = (best == 1);
    bool b = (best == 4);
    bool c = !(best == 3);
    bool d = !b;
    if (a + b + c + d != 1){
      continue;
    }
    if (a) {
      std::cout << 2 << std::endl << "A" << std::endl;
    } else if (b) {
      std::cout << 4 << std::endl << "B" << std::endl;
    } else if (c) {
      std::cout << 1 << std::endl << "C" << std::endl;
    } else {
      std::cout << 3 << std::endl << "D" << std::endl;
    }
  }
  return 0;
}
