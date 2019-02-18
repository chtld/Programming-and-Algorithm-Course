#include <iostream>

int queue(char s[], int index){
  if (s[index] != s[0]) {
    return index;
  } else {
    if (s[index] == '\0') {
      return index - 1;
    } else {
      int result = queue(s, index + 1);
      std::cout << index << " " << result << std::endl;
    }
  }
}

int main(){
  char s[100] = {'\0'};
  std::cin.getline(s, 100);
  int result = queue(s, 0);
  std::cout << 0 << " " << result << std::endl;
  return 0;
}
