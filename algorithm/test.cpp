#include<iostream>
#include <algorithm>
using namespace std;
struct dot {
    int row;
    int column;
    int height;
};
dot matrix[101*101], original[101][101];
int column, row;
int length[101][101];

bool compare(dot lhs, dot rhs) {
    return lhs.height<rhs.height;
}

int maxStep(int i)
{
    int maxStep = 1;
    for (int j = 0; j < i; ++j) {
        int r = matrix[j].row;
        int c = matrix[j].column;
        int h = matrix[j].height;
        // 按老师的“我为人人”的做法做的
        if (r > 1 && original[r-1][c].height > h) {
            length[r-1][c] = max(length[r-1][c], length[r][c] + 1);
            if (length[r-1][c] > maxStep) {
                maxStep = length[r-1][c];
            }
        }
        if (r < row && original[r+1][c].height > h) {
            length[r+1][c] = max(length[r+1][c], length[r][c] + 1);
            if (length[r+1][c] > maxStep) {
                maxStep = length[r+1][c];
            }
        }
        if (c > 1 && original[r][c-1].height > h) {
            length[r][c-1] = max(length[r][c-1], length[r][c] + 1);
            if (length[r][c-1] > maxStep) {
                maxStep = length[r][c-1];
            }
        }
        if (c < column && original[r][c+1].height > h) {
            length[r][c+1] = max(length[r][c+1], length[r][c] + 1);
            if (length[r][c+1] > maxStep) {
                maxStep = length[r][c+1];
            }
        }
    }
    return maxStep;
}

int main()
{
    cin>>row>>column;
    int k = 0;
    for (int i = 1; i < row+1; ++i) {
        for (int j = 1; j < column+1; ++j) {
            matrix[k].row = i;
            matrix[k].column = j;
            cin>>matrix[k].height;
            original[i][j] = matrix[k];
            length[i][j] = 1; // 所有点的滑行距离先设为1
            k++;
        }
    }
    std::sort(matrix, matrix + k, compare);
    int maxLength = maxStep(k);
    cout<<maxLength;
    return 0;
}