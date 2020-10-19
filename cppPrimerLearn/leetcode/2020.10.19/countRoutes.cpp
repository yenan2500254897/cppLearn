#include<iostream>
#include<vector>
#include<algorithm>
/*
1575. 统计所有可行路径
给你一个 互不相同 的整数数组，其中 locations[i] 表示第 i 个城市的位置。同时给你 start，finish 和 fuel 分别表示出发城市、目的地城市和你初始拥有的汽油总量
每一步中，如果你在城市 i ，你可以选择任意一个城市 j ，满足  j != i 且 0 <= j < locations.length ，并移动到城市 j 。
从城市 i 移动到 j 消耗的汽油量为 |locations[i] - locations[j]|，|x| 表示 x 的绝对值。
请注意， fuel 任何时刻都 不能 为负，且你 可以 经过任意城市超过一次（包括 start 和 finish ）。
请你返回从 start 到 finish 所有可能路径的数目。
由于答案可能很大， 请将它对 10^9 + 7 取余后返回。

来源：力扣（LeetCode）
*/
using namespace std;
int M = 1000000007;
int findPath(vector<int>& locations, int start, int finish, int fuel, vector<vector<int>>& dp){
    if(dp[start][fuel] == -1){
        return 0;
    }

    if(dp[start][fuel] > 0){
        return dp[start][fuel];
    }

    for(int index = 0;index<locations.size();index++){
        if(index != start && abs(locations[index]-locations[start])<=fuel){
            dp[start][fuel] += findPath(locations, index, finish, fuel-abs(locations[index]-locations[start]), dp);
            dp[start][fuel] %= M;
        }
    }
    if(start == finish){
        dp[start][fuel] += 1;
        dp[start][fuel] %= M;
    }
    if(dp[start][fuel] == 0){
        dp[start][fuel] = -1;
    }
    return dp[start][fuel]>0?dp[start][fuel]:0;
}

int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    vector<vector<int>> dp(locations.size(),vector<int>(fuel+1, 0));
    //findPath(locations, start, finish, fuel, dp);
    return findPath(locations, start, finish, fuel, dp);
}

int main(){
    // vector<int> locations = {2,3,6,8,4};
    // int start = 1;
    // int finish = 3;
    // int fuel = 5;

    vector<int> locations = {4,3,1};
    int start = 1;
    int finish = 0;
    int fuel = 6;
    cout<<countRoutes(locations, start, finish, fuel)<<endl;
    return 0;
}