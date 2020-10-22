#include<iostream>
#include<vector>
#include<map>

/*
1553. 吃掉 N 个橘子的最少天数
厨房里总共有 n 个橘子，你决定每一天选择如下方式之一吃这些橘子：

吃掉一个橘子。
如果剩余橘子数 n 能被 2 整除，那么你可以吃掉 n/2 个橘子。
如果剩余橘子数 n 能被 3 整除，那么你可以吃掉 2*(n/3) 个橘子。
每天你只能从以上 3 种方案中选择一种方案。

请你返回吃掉所有 n 个橘子的最少天数。

来源：力扣（LeetCode）
*/
using namespace std;

map<int, int> dp;

int minDays(int n) {
    if(n<=1){
        return n;
    }
    if(dp.count(n) != 0){
        return dp[n];
    }
    dp[n] = min(n%2+1+minDays(n/2), n%3+1+minDays(n/3));
    return dp[n];
}

int main(){
    int n = 10;
    cout<<minDays(n)<<endl;
}