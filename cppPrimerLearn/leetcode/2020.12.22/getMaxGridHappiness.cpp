#include<iostream>
#include<vector>
#include<math.h>
#include<cstring>

/*
1659. 最大化网格幸福感
给你四个整数 m、n、introvertsCount 和 extrovertsCount 。有一个 m x n 网格，和两种类型的人：内向的人和外向的人。总共有 introvertsCount 个内向的人和 extrovertsCount 个外向的人。

请你决定网格中应当居住多少人，并为每个人分配一个网格单元。 注意，不必 让所有人都生活在网格中。

每个人的 幸福感 计算如下：

内向的人 开始 时有 120 个幸福感，但每存在一个邻居（内向的或外向的）他都会 失去  30 个幸福感。
外向的人 开始 时有 40 个幸福感，每存在一个邻居（内向的或外向的）他都会 得到  20 个幸福感。
邻居是指居住在一个人所在单元的上、下、左、右四个直接相邻的单元中的其他人。

网格幸福感 是每个人幸福感的 总和 。 返回 最大可能的网格幸福感 。

来源：力扣（LeetCode）
*/
using namespace std;

int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
    int number1 = pow(3, n);
    int number2 = pow(3, n-1);

    int assistant[3][3] = {{0, 0, 0}, {0, -60, -10}, {0, -10, 40}};
    int dp[m*n+1][introvertsCount+1][extrovertsCount+1][number1];
    memset(dp, 0, sizeof(dp));

    for(int coord = m*n-1;coord>=0;coord--)
    {
        int row = coord/n;
        int col = coord%n;
        for(int i=0;i<=introvertsCount;i++)
        {
            for(int j=0;j<=extrovertsCount;j++)
            {
                for(int pre=0;pre<number1;pre++)
                {
                    int next = (pre*3)%number1;
                    if(i>0)
                    {
                        int diff = 120 + (col!=0)*assistant[1][pre%3] + assistant[1][pre/number2];
                        dp[coord][i][j][pre] = max(dp[coord][i][j][pre], diff + dp[coord+1][i-1][j][next+1]);
                    }

                    if(j>0)
                    {
                        int diff = 40 +(col!=0)*assistant[2][pre%3] + assistant[2][pre/number2];
                        dp[coord][i][j][pre] = max(dp[coord][i][j][pre], diff + dp[coord+1][i][j-1][next+2]);
                    }
                    dp[coord][i][j][pre] = max(dp[coord][i][j][pre], dp[coord+1][i][j][next]);
                }
            }
        }
    }
    return dp[0][introvertsCount][extrovertsCount][0];
}

int main()
{
    int m = 2;
    int n= 3;
    int introvertsCount = 1;
    int extrovertsCount = 2;
    cout<< getMaxGridHappiness(m, n, introvertsCount, extrovertsCount)<<endl;
}