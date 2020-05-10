#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int Next[1000005];

void getnext(string str) {
    int j = -1;
    Next[0] = -1;
    for (int i = 0; i < str.size(); ) {
        if (j == -1 || str[i] == str[j]) {
            ++i; ++j;
            Next[i] = j;
            if (i % (i - Next[i]) == 0 && Next[i] != 0) {
                cout << i << " " << i / (i - Next[i]) << endl;
            }
        } else {
            j = Next[j];
        }
    }
}

int main() {
    int cases = 1;
    int N;
    while (cin >> N && N) {
        string str;
        if (N == 0) break;
        cin >> str;
        memset(Next, 0, sizeof(Next));
        cout << "Test case #" << cases << endl;
        getnext(str);
        cases++;
        cout << endl;
    }
    return 0;
}