#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

struct Trie{
    Trie *next[26];
    int num;
    Trie(){
        for (int i = 0; i < 26; ++ i) {
            next[i] = nullptr;
        }
        num = 0;
    }
};

Trie *root = new Trie;

void destory(Trie *p) {
    if(p == nullptr) return;
    for (int i = 0; i < 26; ++ i) {
        destory(p->next[i]);
    }
    delete p;
    p = nullptr;
    return;
}

void insert(char *s){
    Trie *p = root;
    for (int i = 0; s[i]; ++ i) {
        int t = s[i] - 'a';
        if (p->next[t] == nullptr) {
            p->next[t] = new Trie;
        }
        p = p->next[t];
        p->num++;
    }
}

void find(char *s){
    Trie *p = root;
    for (int i = 0; s[i]; ++ i) {
        int t = s[i] - 'a';
        if(p->next[t] == nullptr)
            return;
        p = p->next[t];
        printf("%c", s[i]);
        if (p->num == 1)
            return;
    }
}

int main(){
    char str[1010][21];
    int i = 0;
    while (~scanf("%s", str[i])) {
        insert(str[i]);
        i++;
    }
    for (int j = 0; j < i; ++ j) {
        printf("%s ", str[j]);
        find(str[j]);
        printf("\n");
    }
    destory(root);
    return 0;
}