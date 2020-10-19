#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
/*
1595. 连通两组点的最小成本
给你两组点，其中第一组中有 size1 个点，第二组中有 size2 个点，且 size1 >= size2 。

任意两点间的连接成本 cost 由大小为 size1 x size2 矩阵给出，其中 cost[i][j] 是第一组中的点 i 和第二组中的点 j 的连接成本。如果两个组中的每个点都与另一组中的一个或多个点连接，则称这两组点是连通的。换言之，第一组中的每个点必须至少与第二组中的一个点连接，且第二组中的每个点必须至少与第一组中的一个点连接。

返回连通两组点所需的最小成本。

*/

int connectTwoGroups(vector<vector<int>>& cost){
    int row = cost.size();
    int col = cost[0].size();

    vector<vector<int>> dp(row+1, vector<int>(1<<col, INT_MAX));
    dp[0][0] = 0;
    for(int i=0;i<row;i++){
        for(int j=0;j<(1<<col);j++){
            if(dp[i][j] == INT_MAX){
                continue;
            }
            int number = (~j) & ((1<<col)-1);
            //cout<<number<<endl;

            //选未连接的点，建立连接
            for(int m=1;m<=number;m++){
                int result = dp[i][j];
                int assistant = m;
                if((j & m) == 0){
                    while(assistant!=0){
                        int index = __builtin_ffs(assistant)-1;
                        result += cost[i][index];
                        assistant ^= (1<<index);
                        if(result > dp[i+1][j|m]){
                            break;
                        }
                    }
                    dp[i+1][j|m] = min(dp[i+1][j|m], result);
                }
            }

            //选一个已经连接的点，建立连接
            for(int n=0;n<col;n++){
                if((j & (1<<n)) != 0){
                    // int index2 = __builtin_ffs(n)-1;
                    dp[i+1][j] = min(dp[i+1][j], dp[i][j] + cost[i][n]);
                }
            }
        }
        
    }
    return dp[row][((1<<col)-1)];
}
int main(){
    vector<vector<int>> cost{{93,56,92},{53,44,18},{86,44,69},{54,60,30}};
    //vector<vector<int>> cost{{15, 96}, {36, 2}};
    cout<<connectTwoGroups(cost);
    return 0;
}