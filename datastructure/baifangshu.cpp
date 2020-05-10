#include<iostream>

using namespace std;

struct LoserTree{
    int *tree; // 败者树数组，存放叶子节点的索引
    int *elem; // 叶子节点数组
    int n;     // 当前选手个数
    int LowExt; // 最底层外部节点个数，注意：不是外部节点总数
    int offset; // 最底层外部节点之上的节点总数
    int winner(int a1, int a2); // 赢得规则
    int loser(int a1, int a2); // 输的规则
    void init(int _n, int *_elem);
    void play(int parent, int c1, int c2);
    void replay(int i);
    void print();
};

int LoserTree::winner(int a1, int a2) {
    if (elem[a1] < elem[a2]) return a1;
    else return a2;
}

int LoserTree::loser(int a1, int a2) {
    if (elem[a1] < elem[a2]) return a2;
    else return a1;
}

void LoserTree::play(int parent, int left, int right) {
    tree[parent] = loser(left, right); // 败者索引放在父节点中
    int temp1, temp2;
    temp1 = winner(left, right); // 赢者索引暂存，后续会放到父节点的父节点中
    // 若parent是右孩子，则继续向上比赛
    while (parent > 1 && parent % 2) {
        temp2 = winner(tree[parent/2], temp1);
        tree[parent/2] = loser(tree[parent/2], temp1);
        temp1 = temp2;
        parent /= 2;
    }
    tree[parent/2] = temp1;
}

void LoserTree::init(int _n, int *_elem) {
    n = _n; // 当前选手个数
    elem = _elem; // 叶节点数组
    tree = new int[n + 2];
    int s, i;
    for (s = 1; 2 * s <= n - 1; s += s);
    LowExt = 2 * (n - s);
    offset = 2 * s - 1;
    // 从最底层的外部节点开始比赛，开始play
    for (i = 2; i <= LowExt; i += 2)
        play((offset + i) / 2, i - 1, i);
    // 若节点个数为奇数，说明有一个外部节点需要与一个内部节点进行pk
    if (n % 2) {
        play(n/2, tree[(n - 1)/2], LowExt + 1);
        i = LowExt + 3;
    } else {
        i = LowExt + 2;
    }
    // 其余外部节点之间进行pk
    for (; i <= n; i += 2) {
        play((i - LowExt + n - 1) / 2, i - 1, i);
    }
}

void LoserTree::replay(int i){
    int parent;
    if (i <= LowExt) {
        parent = (i + offset) / 2;
    } else {
        parent = (i - LowExt + n - 1) / 2;
    }
    tree[0] = winner(i, tree[parent]);
    tree[parent] = loser(i, tree[parent]);
    for (; (parent / 2) >= 1; parent /= 2) {
        int temp;
        temp = winner(tree[parent/2], tree[0]);
        tree[parent/2] = loser(tree[parent/2], tree[0]);
        tree[0] = temp;
    }
}

void LoserTree::print(){
    for (int i = 0; i < n; ++ i) {
        cout << elem[tree[i]] << " ";
    }
    cout << endl;
}

int main(){
    int n, m;
    int elem[1000];
    LoserTree loser;
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) {
        cin >> elem[i];
    }
    loser.init(n, elem);
    loser.print();
    int index, val;
    for (int i = 0; i < m; ++ i) {
        cin >> index >> val;
        elem[index + 1] = val;
        loser.replay(index + 1);
        loser.print();
    }
    return 0;
}