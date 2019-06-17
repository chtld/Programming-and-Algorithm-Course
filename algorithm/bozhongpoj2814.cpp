/*
 * 拨钟问题有如下特点：
 * 1) 每个动作最多进行三次，否则动作的效果就会抵消。
 * 2) 最后的结果与执行动作的先后顺序没有关系。
 * 3) 问题的解决有两种思路，一是针对每个动作进行循环，
 *    每个动作有三种可能性，则总共枚举的次数为3的9次方。
 * 4) 上述解决方案没有进行优化，次数较多，另一种思路是
 *    对问题进行细致的分析，可以首先对123这三种动作进行
 *    枚举，则此时钟表的状态已经确定，为了使得ABC三个
 *    钟表的状态恢复，则456三个动作的次数已经确定，此时
 *    需要调整的钟表就只有DEFGHI六个，调整D则动作7确定，
 *    调整F则动作9确定(也可以选择调整E)，最后只要满足
 *    调整GHI的次数相同，E不用调整即达到了目标状态。
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

void moveop(unsigned operations[10][10], unsigned clocks2[10], int op, int op_num){
    for (int j = 1; j < 10; ++ j) {
        clocks2[j] += operations[op][j]*op_num;
        clocks2[j] %= 4;
    }
}

int main(){
    // 保存原始时钟的状态
    unsigned clocks[10] = {0};
    // 保存最终最少的移动次数
    int min_res = 28, tmp  = 0;
    // 保存移动方法
    int op[10] = {0};
    // 保存每个方法对应的移动次数
    int op_num[10] = {0};
    // 9种操作对应的数组
    unsigned operations[10][10] = {
        {0},
        //  A, B, C, D, E, F, G, H, I
        {0, 1, 1, 0, 1, 1, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 1, 1, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 1, 1, 0, 1, 1}
    };
    // clock2记录移动之后的钟表状态
    unsigned clocks2[10] = {0};
    // 保存枚举123的64种情况
    unsigned move123[64][3];
    // 输入钟表的初始状态
    for (int i = 1; i < 10; ++ i) {
        cin >> clocks[i];
    }
    // 将前三个动作的状态进行压缩，共64种可能性
    for (int i = 0; i < 64; ++ i) {
        int num = i;
        // 每次初始化钟表的状态为最开始的状态，并将操作次数置0
        memcpy(clocks2, clocks, sizeof(unsigned)*10);
        memset(op_num, 0, sizeof(unsigned)*10);

        for (int j = 1; j <= 3; ++ j) {
            op_num[j] = num % 4;
            num = num / 4;
            moveop(operations, clocks2, j, op_num[j]);
        }

        // 4,5,6动作的次数
        for (int j = 4; j <= 6; ++ j) {
            op_num[j] = (4 - clocks2[j - 3]) % 4;
            moveop(operations, clocks2, j, op_num[j]);
        }

        op_num[7] = (4 - clocks2[4]) % 4;
        moveop(operations, clocks2, 7, op_num[7]);
        op_num[9] = (4 - clocks2[6]) % 4;
        moveop(operations, clocks2, 9, op_num[9]);

        if (clocks2[5] == 0 && clocks2[7] == clocks2[8] && clocks2[8] == clocks2[9]) {
            op_num[8] = (4 - clocks2[7]) % 4;
            int tmp = 0;
            for (int j = 1; j < 10; ++ j) {
                tmp += op_num[j];
            }
            if (tmp < min_res) {
                min_res = tmp;
                memcpy(op, op_num, sizeof(unsigned) * 10);
            }
        }
    }

    for (int i = 1; i < 10; ++ i) {
        if (op[i] != 0) {
            for (int j = 0; j < op[i]; ++ j)
                cout << i << ' ';
        }
    }
    return 0;
}