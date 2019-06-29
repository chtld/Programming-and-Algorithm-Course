#include<iostream>
#include<cstring>
using namespace std;

char str[101];
int len;
int match(int pos){
    int i;
    i = pos + 1;
    while (1) {
        while (str[i] != '(' && str[i] != ')' && str[i] != 0)
            i++;
        if (str[i] == '(') {
            i = match(i);
        }
        else if (str[i] == ')') {
            str[pos] = ' ';
            str[i] = ' ';
            return i + 1;
        } else {
            str[pos] = '$';
            return len;
        }
    }
}

int main(){
    while (cin.getline(str, 101)) {
        cout << str << endl;
        len = strlen(str);
        int i;
        for (i = 0; i < len; ++i) {
            if (str[i] != '(' && str[i] != ')')
                str[i] = ' ';
        }
        i = 0;
        while (str[i] != 0)
        {
            while(str[i] != 0 && str[i] != '(')
                i++;
            if (str[i] == '(')
                i = match(i);
        }
        i = 0;
        while(str[i] != 0) {
            if (str[i] == ')')
                str[i] = '?';
            i++;
        }
        cout << str << endl;   
    }
    return 0;
}