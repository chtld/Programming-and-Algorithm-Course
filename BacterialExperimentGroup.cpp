#include <iostream>

int main(){
  int n = 0, initial = 0, final = 0;
  std::cin >> n;
  int id[100] = {0};
  double rate[100] = {0.0};
  for (int i = 0; i < n; i++){
    std::cin >> id[i] >> initial >> final;
    rate[i] = (double) final/initial;
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n - i - 1; j++){
      if(rate[j] > rate[j + 1]){
        double temp = rate[j];
        rate[j] = rate[j + 1];
        rate[j + 1] = temp;
        int temp2 = id[j];
        id[j] = id[j + 1];
        id[j + 1] = temp2;
      }
    }
  }

  double maxDiff = 0.0;
  int maxDiffIndex = 0;
  for(int i = 0; i < n - 1 ; i++){
    double diff = rate[i+1] - rate[i];
    if(diff >= maxDiff ){
      maxDiff = diff;
      maxDiffIndex = i; 
    }
  }

  std::cout << n - maxDiffIndex - 1 << std::endl;
  for(int i = maxDiffIndex + 1; i < n; i++){
    std::cout << id[i] << std::endl;
  }
  std::cout << maxDiffIndex + 1 << std::endl;
  for(int i = 0; i <= maxDiffIndex; i++){
    std::cout << id[i] << std::endl;
  }
  return 0;
}
