#include<iostream>
#include<vector>
#include<map>
#include<set>
/*
1434. 每个人戴不同帽子的方案数
总共有 n 个人和 40 种不同的帽子，帽子编号从 1 到 40 。

给你一个整数列表的列表 hats ，其中 hats[i] 是第 i 个人所有喜欢帽子的列表。

请你给每个人安排一顶他喜欢的帽子，确保每个人戴的帽子跟别人都不一样，并返回方案数。

由于答案可能很大，请返回它对 10^9 + 7 取余后的结果。

来源：力扣（LeetCode）
*/
using namespace std;
int M = 1000000007;

int numberWays(vector<vector<int>>& hats) {
    int len = hats.size();
    
    map<int, set<int>> record;
    for(int i=0;i<len;i++){
        for(int hat:hats[i]){
            record[hat-1].insert(i);
        }
    }

    vector<int> dp(1<<len, 0);
    dp[0] = 1;

    for(int i=0;i<40;i++){
        for(int state = (1<<len)-1;state>=0;state--){
            for(auto person:record[i]){
                if(state & (1<<person)){
                    continue;
                }
                int nextState = state | (1<<person);
                dp[nextState] += dp[state];
                dp[nextState] %= M;
            }
        }
    }
    return dp[(1<<len)-1]%M;
}
int main(){
    vector<vector<int>> test{{3,5,1},{3,5}};
    cout<<numberWays(test)<<endl;
    return 0;
}