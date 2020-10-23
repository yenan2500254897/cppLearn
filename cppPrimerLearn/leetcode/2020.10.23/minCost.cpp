#include<iostream>
#include<vector>
#include<iostream>
#include<algorithm>
/*
1547. 切棍子的最小成本
有一根长度为 n 个单位的木棍，棍上从 0 到 n 标记了若干位置。例如，长度为 6 的棍子可以标记如下：



给你一个整数数组 cuts ，其中 cuts[i] 表示你需要将棍子切开的位置。

你可以按顺序完成切割，也可以根据需要更改切割的顺序。

每次切割的成本都是当前要切割的棍子的长度，切棍子的总成本是历次切割成本的总和。对棍子进行切割将会把一根木棍分成两根较小的木棍（这两根木棍的长度和就是切割前木棍的长度）。请参阅第一个示例以获得更直观的解释。

返回切棍子的 最小总成本 。

来源：力扣（LeetCode）
*/
using namespace std;

//dp[left][right]表示切割区间[left][right]的最小代价
//令left< index < right,dp[left][right] = right-left + dp[left][index] + dp[index][right];

//优化准备leftCut和rightCut的准备过程
int findCost(vector<int>& cuts, int left, int right, vector<vector<int>>& dp){
    //不需要切割

    if(left+1 >= right){
        dp[left][right] = 0;
        return 0;
    }

    if(dp[left][right]!=INT_MAX){
        return dp[left][right];
    }

    for(int middle = left+1;middle<right;middle++){
        int cost = cuts[right] - cuts[left];
        if(dp[left][middle] == INT_MAX){
            dp[left][middle] = findCost(cuts, left, middle, dp);
        }

        if(dp[middle][right] == INT_MAX){
            dp[middle][right] = findCost(cuts, middle, right, dp);
        }
        cost += (dp[left][middle] + dp[middle][right]);
        dp[left][right] = min(dp[left][right], cost);
    }
    return dp[left][right];
}
int minCost(int n, vector<int>& cuts) {
    sort(cuts.begin(), cuts.end());
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    int len = cuts.size();
    vector<vector<int>> dp(len, vector<int>(len, INT_MAX));
    return findCost(cuts, 0, len-1, dp);
}

int main(){
    int n = 7;
    vector<int> cuts = {1,3,4,5};
    cout<<minCost(n, cuts)<<endl;
}