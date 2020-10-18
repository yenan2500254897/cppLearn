#include<iostream>
#include<vector>
#include<stdio.h>
/*
1611. 使整数变为 0 的最少操作次数
给你一个整数 n，你需要重复执行多次下述操作将其转换为 0 ：

翻转 n 的二进制表示中最右侧位（第 0 位）。
如果第 (i-1) 位为 1 且从第 (i-2) 位到第 0 位都为 0，则翻转 n 的二进制表示中的第 i 位。
返回将 n 转换为 0 的最小操作次数。

 

来源：力扣（LeetCode）
*/
using namespace std;

int f(int);
int g(int, int);
int f(int n){
    if(n<=1){
        return n;
    }
    int t = 31 - __builtin_clz(n);
    return (1<<t) + g(n^(1<<t), t-1);
}
int g(int n, int t){
    if(t == 0){
        return 1-n;
    }
    if(n & (1<<t)){
        return f(n ^ (1<<t));
    }
    return (1<<t) + g(n, t-1);
}

int minimumOneBitOperations(int n) {
    return f(n);
}

int main(){
    int test = 9;
    cout<<minimumOneBitOperations(test)<<endl;
    return 0;
}