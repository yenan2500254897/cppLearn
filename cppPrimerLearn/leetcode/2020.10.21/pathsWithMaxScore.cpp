#include<iostream>
#include<vector>

/*
1301. 最大得分的路径数目
给你一个正方形字符数组 board ，你从数组最右下方的字符 'S' 出发。

你的目标是到达数组最左上角的字符 'E' ，数组剩余的部分为数字字符 1, 2, ..., 9 或者障碍 'X'。在每一步移动中，你可以向上、向左或者左上方移动，可以移动的前提是到达的格子没有障碍。

一条路径的 「得分」 定义为：路径上所有数字的和。

请你返回一个列表，包含两个整数：第一个整数是 「得分」 的最大值，第二个整数是得到最大得分的方案数，请把结果对 10^9 + 7 取余。

如果没有任何路径可以到达终点，请返回 [0, 0] 。

来源：力扣（LeetCode）
*/
using namespace std;

int M = 1000000007;
vector<int> pathsWithMaxScore(vector<string>& board) {
    int row = board.size();
    int col = board[0].size();
    vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(2, 0)));
    dp[0][0][1] = 1;

    int dir[3][2] = {{-1,0}, {0, -1}, {-1, -1}};
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            
            for(int k=0;k<3;k++){
                int preR = i+dir[k][0];
                int preC = j+dir[k][1];
                if(preR >= 0 && preC >= 0 && board[preR][preC] != 'X'){
                    if(dp[preR][preC][0]>=dp[i][j][0]){
                        if(dp[preR][preC][0] == dp[i][j][0]){
                            if(dp[i][j][0] !=0 || (preR==0 && preC ==0)){
                                dp[i][j][1] += dp[preR][preC][1];
                                dp[i][j][1] %= M;
                            }
                        }else{
                            dp[i][j][0] = dp[preR][preC][0];
                            dp[i][j][1] = dp[preR][preC][1];
                        }
                    }
                }

            }
            if(!(dp[i][j][0] == 0 && dp[i][j][1] == 0) && (board[i][j]>='1' && board[i][j]<='9')){
                dp[i][j][0] += (board[i][j]-'0');
            }
        }
    }
    vector<int> result = {dp[row-1][col-1][0], dp[row-1][col-1][1]};
    return result;
}

int main(){
    vector<string> test = {"E23","2X2","12S"};
    vector<int> result = pathsWithMaxScore(test);
    cout<<result[0]<<"  "<<result[1]<<endl;
    //cout<<'1'-'0'<<endl;
}