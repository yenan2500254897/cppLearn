#include<iostream>
#include<vector>

/*
1641. 统计字典序元音字符串的数目
给你一个整数 n，请返回长度为 n 、仅由元音 (a, e, i, o, u) 组成且按 字典序排列 的字符串数量。

字符串 s 按 字典序排列 需要满足：对于所有有效的 i，s[i] 在字母表中的位置总是与 s[i+1] 相同或在 s[i+1] 之前。
dp[i]表示字符串以i开始i=1,2,3,4,5 对应a, e, i, o, u

来源：力扣（LeetCode）
*/
using namespace std;

int countVowelStrings(int n) 
{
    if(n == 1)
    {
        return 5; 
    }

    int dp[6] = {0,1,1,1,1,1};
    int assistant[6] = {0, 0, 0, 0, 0, 0};
    int index= 1;
    int total = 5;
    while(index<n)
    {
        int temp = 0;
        int left = 0;
        for(int i=1;i<=5;i++)
        {
            assistant[i] = total - left;
            temp += assistant[i];
            left += dp[i];
        }
        swap(assistant, dp);
        total = temp;
        index++;
    }

    int result = 0;
    for(auto item:dp)
    {
        result += item;
    }
    return result;
}

int main()
{
    // int n = 2;
    int n = 3;
    cout<<countVowelStrings(n)<<endl;
    return 0;
}