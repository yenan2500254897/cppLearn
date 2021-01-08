#include<iostream>
#include<string>
#include<set>
#include<math.h>
#include<unordered_set>

/*
1044. 最长重复子串
给出一个字符串 S，考虑其所有重复子串（S 的连续子串，出现两次或多次，可能会有重叠）。

返回任何具有最长可能长度的重复子串。（如果 S 不含重复子串，那么答案为 ""。）

来源：力扣（LeetCode）
思路：search用来判断s中是否存在长度为len的重复子串
findSolution(s, left, right)用来判断s中是否存在长度在[left, right)的子串,
mid = (left + right)/2  如果存在长度为mid的重复子串，则findSolution(s, mid+1, right), 否则findSolution(s, left, mid)

*/
using namespace std;

string retString = "";
// bool search(string& s, int len)
// {
//     long double result = 0;
//     set<long double> assistant;
//     for(int j=len-1;j>=0;j--)
//     {
//         result *= 26;
//         result += (s[j]-'a');
//     }
//     assistant.insert(result);

//     for(int start=1;start+len-1<s.size();start++)
//     {
//         result /= 26;
//         result = floor(result);
//         long double value = pow((long double)26, (long double)(len-1))*(s[start+len-1]-'a');
//         result += value;
//         if(assistant.count(result)>0)
//         {
//             string subStr = s.substr(start, len);
//             if(retString.empty() || retString.size()<subStr.size())
//             {
//                 retString = subStr;
//             }
//             return true;
//         }
//         assistant.insert(result);
//     }
//     return false;
// }

bool search(string& s, int len)
{
    unordered_set<string> assistant;
    //set<string> assistant;
    assistant.insert(s.substr(0, len));
    string result = "";
    for(int start=1;start+len-1<s.size();start++)
    {
        result = s.substr(start, len);
        if(assistant.count(result)>0)
        {
            if(retString.empty() || retString.size()<result.size())
            {
                retString = result;
            }
            return true;
        }
        assistant.insert(result);
    }
    return false;
}

int findSolution(string& s, int left, int right)
{
    if(left == right)
    {
        return left-1;
    }

    int mid = (left + right)/2;
    if(!search(s, mid))
    {
        return findSolution(s, left, mid);
    }
    return findSolution(s, mid+1, right);
}

string longestDupSubstring(string s) 
{
    int len = findSolution(s, 1, s.size());
    return retString;
}

int main()
{
    //string s = "banana";
    //string s = "abcd";
    string s = "zxcvdqkfawuytt";
    //cout<<s.substr(1,3)<<endl;
    cout<<longestDupSubstring(s)<<endl;
    return 0;
}