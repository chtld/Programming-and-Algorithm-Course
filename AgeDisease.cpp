#include <iostream>
#include <iomanip>

int main(){
  int n = 0;
  std::cin >> n;
  int age18 = 0, age35 = 0, age60 = 0, ageMore = 0;
  for(int i = 0; i < n; i++){
    int age = 0;
    std::cin >> age;
    if(age <= 18){
      age18++;
    } else if(age <= 35){
      age35++;
    } else if(age <= 60){
      age60++;
    } else {
      ageMore++;
    }
  }
  std::cout << std::fixed << std::setprecision(2);
  std::cout << "1-18: " << age18*100.0/n << "%" <<std::endl;
  std::cout << "19-35: " << age35*100.0/n << "%" <<std::endl;
  std::cout << "36-60: " << age60*100.0/n << "%" <<std::endl;
  std::cout << "60-: " << ageMore*100.0/n << "%" <<std::endl;
}
