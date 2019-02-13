#include <iostream>

int main(){
  char s1[80] = {'\0'}, s2[80] = {'\0'};
  while (std::cin.getline(s1, 80) && std::cin.getline(s2, 80)) {
    int index = 0;
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
      if (s1[i] >= 'A' && s1[i] <= 'Z') {
        s1[i] += ('a' - 'A');
      }
      if (s2[i] >= 'A' && s2[i] <= 'Z') {
        s2[i] += ('a' - 'A');
      }
      if (s1[i] < s2[i] || s1[i] == '\0'){
        index = -1;
        break;
      } else if (s1[i] > s2[i] || s2[i] == '\0'){
        index = 1;
        break;
      }
    }
    if (index == -1){
      std::cout << "<" << std::endl;
    } else if (index == 1){
      std::cout << ">" << std::endl;
    } else {
      std::cout << "=" << std::endl;
    }
  }
}
