#include<iostream>
#include<string>
#include<vector>

/*
1531. 压缩字符串 II
行程长度编码 是一种常用的字符串压缩方法，它将连续的相同字符（重复 2 次或更多次）替换为字符和表示字符计数的数字（行程长度）。例如，用此方法压缩字符串 "aabccc" ，将 "aa" 替换为 "a2" ，"ccc" 替换为` "c3" 。因此压缩后的字符串变为 "a2bc3" 。

注意，本问题中，压缩时没有在单个字符后附加计数 '1' 。

给你一个字符串 s 和一个整数 k 。你需要从字符串 s 中删除最多 k 个字符，以使 s 的行程长度编码长度最小。

请你返回删除最多 k 个字符后，s 行程长度编码的最小长度 。

思路：dp[i][j]表示s[1..i](s的下标从1开始)，删除j个字符后，s 行程长度编码的最小长度 。
当考虑第i+1个字符时，如果不保留，则dp[i][j] = dp[i-1][j-1];
如果考虑保留，则考虑与索引i之前且等于s[i]的字符pre合并，pre的特征是和s[i]之间最多隔j个不同的字母，转移方程见67行

来源：力扣（LeetCode）
*/
using namespace std;

int cost(int value)
{
    if(value == 1)
    {
        return 1;
    }else if(value<10)
    {
        return 2;
    }else if(value<100)
    {
        return 3;
    }else
    {
        return 4;
    }
    return 0;
    
}

int getLengthOfOptimalCompression(string s, int k) 
{
    int len = s.size();
    if(k==len)
    {
        return 0;
    }
    vector<vector<int>> dp(len+1, vector<int>(k+1, INT_MAX>>1));
    dp[0][0] = 0;
    
    for(int i=1;i<=len;i++)
    {
        for(int j=0;j<=k&&j<=i;j++)
        {
            if(j-1>=0)
            {
                dp[i][j] = dp[i-1][j-1];
            }
            int diff = 0;
            int common = 0;
            for(int l=i;l>=1 && diff<=j;l--)
            {
                if(s[i-1] == s[l-1])
                {
                    common++;
                    dp[i][j] = min(dp[i][j], dp[l-1][j-diff]+cost(common));
                }
                else
                {
                    diff++;
                }
                
            }
        }
    }
    return dp[len][k];
}

int main()
{
    string s = "aaabcccd";
    int k = 2;
    // string s = "aaaaaaaaaaa";
    // int k = 0;
    cout<<getLengthOfOptimalCompression(s, k)<<endl;
    return 0;
}