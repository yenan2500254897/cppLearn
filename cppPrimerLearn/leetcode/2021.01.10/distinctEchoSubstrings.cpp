#include<iostream>
#include<string>
#include<vector>
#include<set>

/*
1316. 不同的循环子字符串
给你一个字符串 text ，请你返回满足下述条件的 不同 非空子字符串的数目：

可以写成某个字符串与其自身相连接的形式（即，可以写为 a + a，其中 a 是某个字符串）。
例如，abcabc 就是 abc 和它自身连接形成的。

 

来源：力扣（LeetCode）
*/
using namespace std;

// set<int> record;
// int base = 31;
// int mod = 1000000007;
// int cal(string text, int left, int right)
// {
//     int result = 0;

//     for(int i=left;i<=right;i++)
//     {
//         result = ((long long)result*base + (text[i]-'a'+1))%mod;
//     }
//     return result;
// }

// int sumTotal(int left, int right, int len)
// {
//     int total = 1;
//     for(int i=1;i<=len;i++)
//     {
//         total = ((long long)total*base)%mod;
//     }
//     total = ((long long)total*left)%mod;
//     total = ((long long)total+right)%mod;
//     return total;
// }

set<string> record;
int distinctEchoSubstrings(string text) 
{
    int len = text.size();
    for(int right=0;right<len;right++)
    {
        for(int left=0;left<right;left++)
        {
            if((right-left+1)%2==0)
            {
                int half = (right-left+1)/2;
                if(text[left] == text[left+half] && text[right]==text[left+half-1])
                {
                    string lStr = text.substr(left, half);
                    string rStr = text.substr(left+half, half);
                    if(lStr == rStr)
                    {
                        record.insert(lStr+rStr);
                    }
                }
            }
        }
    }

    return record.size();
}

int main()
{
    string text = "abcabcabc";
    cout<<distinctEchoSubstrings(text)<<endl;
    return 0;
}