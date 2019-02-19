#include <iostream>

int queue(char s[], int index){
  if (s[index] != s[0]) {
    return index;
  } else {
      int result = queue(s, index + 1);
      std::cout << index << " " << result << std::endl;
      return queue(s, result + 1);
  }
}

int main(){
  char s[100] = {'\0'};
  std::cin.getline(s, 100);
  int result = queue(s, 1);
  std::cout << 0 << " " << result << std::endl;
  return 0;
}
