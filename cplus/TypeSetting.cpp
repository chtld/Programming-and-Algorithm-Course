#include <iostream>
#include <cstring>
int main(){
  int n = 0;
  std::cin >> n;
  char word[45] = {'\0'}, sentence[85] = {'\0'};
  for (int i = 0; i < n; i++) {
    std::cin >> word;
    int lengthWord = strlen(word);
    int lengthSentence = strlen(sentence);
    if (lengthSentence + lengthWord + 1 > 80) {
      std::cout << sentence << std::endl;
      sentence[0] = '\0';
      strcat(sentence, word);
    } else {
      if (lengthSentence != 0) sentence[lengthSentence] = ' ';
      sentence[lengthSentence + 1] = '\0';
      strcat(sentence, word);
    }
    if (i == n - 1) std::cout << sentence << std::endl;
  }
  return 0;
}
