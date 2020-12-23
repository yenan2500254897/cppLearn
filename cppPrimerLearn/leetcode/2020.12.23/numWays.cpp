#include<iostream>
#include<vector>
#include<map>
#include<set>
#include <cstring>
/*
1639. 通过给定词典构造目标字符串的方案数
给你一个字符串列表 words 和一个目标字符串 target 。words 中所有字符串都 长度相同  。

你的目标是使用给定的 words 字符串列表按照下述规则构造 target ：

从左到右依次构造 target 的每一个字符。
为了得到 target 第 i 个字符（下标从 0 开始），当 target[i] = words[j][k] 时，你可以使用 words 列表中第 j 个字符串的第 k 个字符。
一旦你使用了 words 中第 j 个字符串的第 k 个字符，你不能再使用 words 字符串列表中任意单词的第 x 个字符（x <= k）。也就是说，所有单词下标小于等于 k 的字符都不能再被使用。
请你重复此过程直到得到目标字符串 target 。
请注意， 在构造目标字符串的过程中，你可以按照上述规定使用 words 列表中 同一个字符串 的 多个字符 。

请你返回使用 words 构造 target 的方案数。由于答案可能会很大，请对 109 + 7 取余 后返回。

（译者注：此题目求的是有多少个不同的 k 序列，详情请见示例。）

来源：力扣（LeetCode）
*/
using namespace std;

int numWays(vector<string>& words, string target) {
    int targetLen = target.size();
    int wordsLen = words[0].size();

    vector<vector<long long>> dp(wordsLen+1, vector<long long>(targetLen+1, 0));

    for(int i = 0;i<=wordsLen ;i++)
    {
        dp[i][0] = 1;
    } 

    //map存在扩缩容问题，会导致超时
    // map<int, multiset<char>> record;
    // for(int index = 0;index<wordsLen;index++)
    // {
    //     for(int i=0;i<words.size();i++)
    //     {
    //         record[index+1].insert(words[i][index]);
    //     }
    // }
    int record[wordsLen+1][26];
    
    memset(record, 0, sizeof(record));
    for(int index = 0;index<wordsLen;index++)
    {
        for(int i=0;i<words.size();i++)
        {
            record[index+1][words[i][index]-'a']++;
        }
    }

    int limit = 1000000007;
    for(int m = 1;m<=wordsLen;m++)
    {
        for(int n=1;n<=min(m, targetLen);n++)
        {
            int circle = record[m][target[n-1]-'a'];
            dp[m][n] += ((circle*dp[m-1][n-1])%limit);
            dp[m][n] %= limit;

            dp[m][n] += dp[m-1][n];
            dp[m][n] %= limit;
        }
    }
    return dp[wordsLen][targetLen];
}

int main()
{
    vector<string> words = {"acca","bbbb","caca"};
    string target = "aba";
    cout<<numWays(words, target)<<endl;
}