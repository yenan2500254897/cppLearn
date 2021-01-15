#include<iostream>
#include<set>
#include<string>

/*
1044. 最长重复子串
给出一个字符串 S，考虑其所有重复子串（S 的连续子串，出现两次或多次，可能会有重叠）。

返回任何具有最长可能长度的重复子串。（如果 S 不含重复子串，那么答案为 ""。）

来源：力扣（LeetCode）

思路：用二分的思路判断可以重复的字符串的最大长度。
难点：用数值的方式表示字符串，无法解决s[i...j]到s[i+1...j+1]的数值表示计算
*/
using namespace std;
string result = "";
bool search(string s, int len)
{
    set<string_view> record;
    string_view s_v = s;
    for(int i=0;i+len<=s.size();i++)
    {
        string_view temp = s_v.substr(i, len);
        if(record.count(temp)!=0)
        {
            if(temp.size()>result.size())
            {
                result = s.substr(i, len);
            }
            return true;
        }
        record.insert(temp);
    }
    return false;
}
string longestDupSubstring(string s) 
{
    int left = 1;
    int right = s.size()-1;
    while (left<=right)
    {
        int mid = (left+right)/2;
        if(search(s, mid))
        {
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
        
    }
    return result;
}

int main()
{
    string s="banana";
    cout<<longestDupSubstring(s)<<endl;
    return 0;
}