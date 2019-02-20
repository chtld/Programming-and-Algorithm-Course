#include <iostream>
#include <cstring>
#include <iomanip>
void strexchange(char s1[], char s2[]){
  for (int i = 0; i < strlen(s1); i++) {
    char temp = s1[i];
    s1[i] = s2[i];
    s2[i] = temp;
  }
}

void douexchange(double *a, double *b){
  double temp = *a;
  *a = *b;
  *b = temp;
}


int main(){
  int m = 0;
  double a = 0.0, servity[50] = {0.0};
  char str[50][4] = {'\0'};
  std::cin >> m >> a;
  if (m == 0) {
    std::cout << "None." << std::endl;
  }
  for (int i = 0; i < m; i++) {
    std::cin >> str[i] >> servity[i];
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m - i - 1; j++) {
      if (servity[j] < servity[j + 1]) {
        strexchange(str[j], str[j + 1]);
        douexchange(&servity[j], &servity[j + 1]);
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if (servity[i] >= a) {
      std::cout << str[i] << " "<< std::fixed << std::setprecision(1) <<servity[i] << std::endl;;
    } else if (i == 0){
      std::cout << "None." << std::endl;
    }
  }
}
