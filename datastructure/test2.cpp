#include<iostream>
#include<cstring>
#include<string>
#include<sstream>
using namespace std;

string dec2hex(int i)
{
stringstream ioss; //定义字符串流
string s_temp; //存放转化后字符
ioss << hex << i; //以十六制形式输出
ioss >> s_temp;
return s_temp;
}

int main () {
    string str1[513], str2[513];
    cin >> str1[0];
    //int num1 = atoi(str1[0].c_str());
    char *p;
    long num1 = strtol( str1[0].c_str(), & p, 16 );
    int num2 = 1;
    for (int i = 1; i < num1; ++ i) {
        cin >> str1[i];
        if (str1[i] == "A") {
            str2[num2] = "12";
            num2++;
            str2[num2] = "34";
            num2++;
        } else if (str1[i] == "B") {
            str2[num2] = "AB";
            num2++;
            str2[num2] = "CD";
            num2++;            
        } else {
            str2[num2] = str1[i];
            num2++;
        }
    }
    str2[0] = dec2hex(num2);
    for (int i = 0; i < num2; ++ i) {
        cout << str2[i] << " ";
    }
    cout << endl;
    return 0;
}