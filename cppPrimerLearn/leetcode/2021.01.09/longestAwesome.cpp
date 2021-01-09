#include<iostream>
#include<string>
#include<vector>

/*
1542. 找出最长的超赞子字符串
给你一个字符串 s 。请返回 s 中最长的 超赞子字符串 的长度。

「超赞子字符串」需满足满足下述两个条件：

该字符串是 s 的一个非空子字符串
进行任意次数的字符交换后，该字符串可以变成一个回文字符串

//用树状数组来判断一个区间是否可以变为回文字符串 ？未成功
思路：一次判断s中是否存在长度为len的回文字符串
用二进制数字number表示0-9中各个数字的奇偶性，如果number中存在2个以上的1，说明存在两个不同的数有奇数个，显然不可能是回文字符串。
来源：力扣（LeetCode）
*/
using namespace std;

int result = 0;

// bool isValid(vector<int>& assistant)
// {
//     int total = 0;
//     for(int i=0;i<assistant.size();i++)
//     {
//         total += assistant[i];
//         if(total>=2)
//         {
//             return false;
//         }
//     }
//     return true;
// }

bool isValid(int value)
{
    return __builtin_popcount(value)<2;
}
bool isAwesome(string& s, int len)
{
    int value = 0;
    for(int i=0;i<len;i++)
    {
        char cur = s[i];
        int index = cur-'0';
        value ^= (1<<index);
    }
    if(isValid(value))
    {
        result = len;
        return true;
    }
    //性能损耗在这里
    for(int j=1;j+len-1<s.size();j++)
    {
        int pre = s[j-1]-'0';
        int next = s[j+len-1]-'0';
        value ^= (1<<pre);
        value ^= (1<<next);
        //这里是改进点，不一定要isValid
        if(isValid(value))
        {
            result = len;
            return true;
        }
    }
    return false;
}

int longestAwesome(string s) 
{
    for(int i=s.size();i>0;i--)
    {
        if(isAwesome(s, i))
        {
            break;
        }
    }
    return result;
}

int main()
{
    string s = "213123";
    //string s = "12345678";
    //string s = "10120";
    cout<<longestAwesome(s)<<endl;
}