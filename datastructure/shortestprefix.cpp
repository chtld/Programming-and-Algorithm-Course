#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Trie {
    struct TrieNode{
        int count;
        TrieNode *next[27];
        TrieNode(int c){
            count = c;
            for (int i = 0; i < 27; ++ i) {
                next[i] = NULL;
            }
        }
    };
    TrieNode *root;
    Trie(){
        root = new TrieNode(0);
    }
    void insert(string str) {
        TrieNode* cur = root;
        for (int i = 0; i < str.size(); ++ i) {
            if (cur->next[str[i] - 'a'] == NULL) {
                cur->next[str[i] - 'a'] = new TrieNode(0);
            }
            cur = cur->next[str[i] - 'a'];
            cur->count++;
        }
        return;
    }
    int findsp(string str) {
        TrieNode* cur = root;
        for (int i = 0; i < str.size(); ++ i) {
            if (cur->next[str[i] - 'a'] == NULL) {
                return -1;
            }
            if (cur->next[str[i] - 'a']->count == 1) {
                return i + 1;
            }
            cur = cur->next[str[i] - 'a'];
        }
        return str.size();
    }
};


int main(){
    Trie trie;
    vector<string> vstr;
    string str;
    while (getline(cin, str)) {
        if (str[0] == 0) break;
        vstr.push_back(str);
        trie.insert(str);
    }
    for (int i = 0; i < vstr.size(); ++ i) {
        int index = trie.findsp(vstr[i]);
        cout << vstr[i] << " " << vstr[i].substr(0, index) << endl;
    }
    return 0;
}