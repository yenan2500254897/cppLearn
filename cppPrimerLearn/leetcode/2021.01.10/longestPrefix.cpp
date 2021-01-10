#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

/*
1392. 最长快乐前缀
「快乐前缀」是在原字符串中既是 非空 前缀也是后缀（不包括原字符串自身）的字符串。

给你一个字符串 s，请你返回它的 最长快乐前缀。

如果不存在满足题意的前缀，则返回一个空字符串。

来源：力扣（LeetCode）
思路：Rabin-Karp 字符串编码
将字符串以base进制数的方式表示为number，计算number的十进制数，然后判断两个十进制数是否一致，来判断两个字符串是否相等。
（将base进制转换为10进制可能会产生溢出，因此需要对一个很大的质数求余）
*/
using namespace std;

// string longestPrefix(string s) 
// {
//     int len = s.size();
//     string result = "";
//     int curLen = len-1;
//     int left, right;
//     while(curLen<len)
//     {
//         left = curLen-1;
//         right = len-1;
//         //性能损耗在这里，可能判断了很多次，发现构不成最长快乐前缀
//         while(left>=0 && right>left)
//         {
//             if(s[left]!=s[right])
//             {
//                 break;
//             }
//             left--;
//             right--;
//         }
//         if(left<0)
//         {
//             result = s.substr(0, curLen);
//             break;
//         }
//         curLen--;
//     }
//     return result;
// }

string longestPrefix(string s) 
{
    int len = s.size();
    int base = 31;
    int mod = 1000000007;
    int prefix = 0;
    int suffix = 0;
    int mul = 1;
    int result = 0;
    for(int i=1;i<len;i++)
    {
        prefix = ((long long)prefix*base+(s[i-1]-'a'+1))%mod;
        suffix = ((long long)mul*(s[len-i]-'a'+1)+suffix)%mod;
        if(prefix == suffix)
        {
            result = i;
        }
        mul = ((long long)mul*base)%mod;
    }
    return s.substr(0, result);
}

int main()
{
    string s="level";
    //string s = "ababab";
    //string s = "leetcodeleet";
    // string s = "acccbaaacccbaac";
    //string s = "abbcbbccaaaaaabcbbaccccaabbcbbccaa";
    cout<<longestPrefix(s)<<endl;
    return 0;
}