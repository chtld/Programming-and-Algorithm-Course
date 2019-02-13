#include <iostream>
#include <cstring>
int main(){
  char str[11] = {'\0'}, substr[4] = {'\0'};
  while (std::cin >> str >> substr) {
    int index = 0, max = 0;
    for (int i = 0; i < strlen(str); i++) {
      if(str[i] > max){
        index = i;
        max = str[i];
      }
    }
    for (int i = strlen(str); i > index; i--) {
      str[i + 3] = str[i];
    }
    for (int i = 0; i < 3; i++) {
      str[index + 1 + i] = substr[i];
    }
    std::cout << str << std::endl;
    memset(str, 0x00, sizeof(char) * 11);
  }
  return 0;
}
