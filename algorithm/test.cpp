//lambda_test.cc
#include <string.h>
#include <stdio.h>
#include <memory>
#include <functional>
#include <iostream>

using namespace std;

int main() {
    int r = 0;

    // lambda，是一个可执行对象，类型是void (int* )
    auto updateLambda = [](int* res) { (*res)++; };
    // 将lambda赋值给callback，后者类型是 void (), 由于签名不符，需要bind做适配
    std::function<void ()> callback = std::bind(updateLambda, &r);

    // 执行callback
    callback();

    // 现在，r应该递增为1
    cout << "From main: r = " << r << endl;
    return 0;
}