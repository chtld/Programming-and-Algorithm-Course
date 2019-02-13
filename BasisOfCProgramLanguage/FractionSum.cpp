#include <iostream>

int main(){
  int n = 0, sumn = 0, sumd = 1;
  std::cin >> n;
  while(n--){
    int deno = 1, num = 0;
    char slash = '/';
    std::cin >> num >> slash >> deno;
    sumn = sumn * deno + sumd * num;
    sumd = sumd * deno;
    int a = sumn, b = sumd, c = 0;
    while(b){
      c = b; b = a % b; a = c;
    }
    int gcd  = a;
    sumn /= gcd;
    sumd /= gcd;
  }
  if(sumd > 1){    
    std::cout << sumn << "/" << sumd << std::endl;
  } else {
    std::cout << sumn << std::endl;
  }
  return 0;
}
