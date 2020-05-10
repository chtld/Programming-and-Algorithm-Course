#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

enum token_type {
    number,
    unit,
    negative
};

struct token {
    string str;
    int value;
    token_type type;
    token(string _str, int _value, token_type _type) {
        str = _str;
        value = _value;
        type = _type;
    }
};

token toketable[] = {
    {"zero", 0, number},
    {"one", 1, number},
    {"two", 2, number},
    {"three", 3, number},
    {"four", 4, number},
    {"five", 5, number},
    {"six", 6, number},
    {"seven", 7, number},
    {"eight", 8, number},
    {"nine", 9, number},
    {"ten", 10, number},
    {"eleven", 11, number},
    {"twelve", 12, number},
    {"thirteen", 13, number},
    {"fourteen", 14, number},
    {"fifteen", 15, number},
    {"sixteen", 16, number},
    {"seventeen", 17, number},
    {"eighteen", 18, number},
    {"nineteen", 19, number},
    {"twenty", 20, number},
    {"thirty", 30, number},
    {"forty", 40, number},
    {"fifty", 50, number},
    {"sixty", 60, number},
    {"seventy", 70, number},
    {"eighty", 80, number},
    {"ninety", 90, number},
    {"hundred", 100, unit},
    {"thousand", 1000, unit},
    {"million", 1000000, unit},
    {"negative", -1, negative}
};

vector<token> spilt(string input) {
    vector<token> res;
    stringstream ss(input);
    string temp;
    while (ss >> temp) {
        for (int i = 0; i < sizeof(toketable)/sizeof(toketable[0]); ++ i) {
            if (temp == toketable[i].str) { 
                res.push_back(token(temp, toketable[i].value, toketable[i].type));
                break;
            }
        }
    }
    reverse(res.begin(), res.end());
    return res;
}


long parse(const string& input) {
    long res = 0;
    vector<token> temp = spilt(input);
    bool nega = false;
    long currentunitvalue = 1;
    for (int i = 0; i < temp.size(); ++ i) {
        switch (temp[i].type) {
            case number:
            res += temp[i].value * currentunitvalue;
            break;
            
            case unit:
            if (temp[i].value >= currentunitvalue) {
                currentunitvalue = temp[i].value;
            } else {
                currentunitvalue *= temp[i].value;
            }
            break;

            case negative:
            nega = true;
            break;
        }
    }
    if (nega) res = -res;
    return res;
}



int main(){
    while (true) {
        string input;
        getline(cin, input);
        if (input.empty()) break;
        cout << parse(input) << endl;
    }    
    return 0;
}