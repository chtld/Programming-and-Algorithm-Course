#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Dict{
    char foreign[11];
    char english[11];
};

Dict dict[100000];

bool compare(const Dict &a, const Dict &b) {
    return strcmp(a.foreign, b.foreign) < 0;
}

int main(){
    int num = 0;
    char word[11];
    while (true) {
        scanf("%s %s", dict[num].english, dict[num].foreign);
        num++;
        cin.get();
        if (cin.peek() == '\n')
            break;
    }
    sort(dict, dict + num, compare);
    int left, right, mid, flag;
    while (scanf("%s", word) != EOF) {
        left = 0;
        right = num;
        while (left < right) {
            mid = left + (right - left) / 2;
            flag = strcmp(dict[mid].foreign, word);
            if (flag == 0) {
                break;
            } else if (flag < 0) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if(left >= right)
            printf("eh\n");
        else
            printf("%s\n", dict[mid].english);
        
    }
    return 0;
}