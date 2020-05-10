#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;
int minheap[100005];
int len = 0;


void shiftup(int index) {
    int temp = minheap[index];
    int parent = (index - 1) / 2;
    while (index > 0 && minheap[parent] > temp) {
        minheap[index] = minheap[parent];
        index = parent;
        parent = (index - 1) / 2;
    }
    minheap[index] = temp;
}

void shiftdown(int index) {
    int left = 2 * index + 1;
    int tmp = minheap[index];
    while (left < len) {
        if (left < len - 1 && minheap[left] > minheap[left + 1])
            left++;
        if (tmp > minheap[left]) {
            minheap[index] = minheap[left];
            index = left;
            left = 2 * left + 1;
        } else {
            break;
        }
    }
    minheap[index] = tmp;
    return;
}

void insert(int u) {
    minheap[len] = u;
    len++;
    shiftup(len - 1);
}

void pop() {
    if (len == 0) return;
    cout << minheap[0] << endl;
    minheap[0] = minheap[len - 1];
    len--;
    shiftdown(0);
}
int main(){
    int cases = 0;
    int n;
    int type; 
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        len = 0;
        while (n --) {
            scanf("%d", &type);
            if (type == 1) {
                int u;
                scanf("%d", &u);;
                insert(u);
            } else {
                pop();
            }
        }
    }
    return 0;
}