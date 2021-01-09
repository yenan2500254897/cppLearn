#include<iostream>
#include<string>
#include<vector>

/*
1542. 找出最长的超赞子字符串
给你一个字符串 s 。请返回 s 中最长的 超赞子字符串 的长度。

「超赞子字符串」需满足满足下述两个条件：

该字符串是 s 的一个非空子字符串
进行任意次数的字符交换后，该字符串可以变成一个回文字符串

来源：力扣（LeetCode）
*/
using namespace std;

int result = 0;

bool isValid(vector<int>& input)
{
    int len = input.size();
    int number = 0;
    for(int i=0;i<len;i++)
    {
        if(input[i]%2 == 1)
        {
            if(number>0)
            {
                return false;
            }
            number++;
        }
    }
    return true;
}

bool isAwesome(string& s, int len)
{
    vector<int> assistant(10, 0);
    for(int i=0;i<len;i++)
    {
        assistant[s[i]-'0']++;
    }
    if(isValid(assistant))
    {
        result = len;
        return true;
    }
    for(int j=1;j+len-1<s.size();j++)
    {
        assistant[s[j-1]-'0']--;
        assistant[s[j+len-1]-'0']++;
        //这里是改进点，不一定要isValid
        if(isValid(assistant))
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