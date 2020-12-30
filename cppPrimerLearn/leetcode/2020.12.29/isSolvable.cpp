#include<iostream>
#include<vector>
#include<set>
#include<map>
/*
1307. 口算难题
给你一个方程，左边用 words 表示，右边用 result 表示。

你需要根据以下规则检查方程是否可解：

每个字符都会被解码成一位数字（0 - 9）。
每对不同的字符必须映射到不同的数字。
每个 words[i] 和 result 都会被解码成一个没有前导零的数字。
左侧数字之和（words）等于右侧数字（result）。 
如果方程可解，返回 True，否则返回 False。

来源：力扣（LeetCode）
question:超时了，时间复杂度过大，见63、64行
*/
using namespace std;

bool findSolution(vector<string> words, string result, map<char,int> record)
{
    int left = 0;
    for(auto item:words)
    {
        int temp = 0;
        for(auto ch:item)
        {
            temp*=10;
            temp+=record[ch];
        }
        left += temp;
    }

    int right = 0;
    for(auto ch:result)
    {
        right*=10;
        right+=record[ch];
    }
    return left==right;
}

bool isSolvable(vector<string>& words, string result) 
{
    set<char> charSet;
    set<char> first;
    for(auto item:words)
    {
        //cout<<item<<endl;
        first.insert(item.front());
        charSet.insert(item.begin(), item.end());
    }
    //cout<<result<<endl;
    first.insert(result.front());
    charSet.insert(result.begin(), result.end());
    vector<int> charVector;
    charVector.insert(charVector.end(), charSet.begin(),charSet.end());

    int len = charSet.size();
    //用数字去匹配字母，循环次数太大，超时
    long long limit = ((long long)1<<(len*4));
    for(long long i=1;i<limit;i++)
    {
        //cout<<i<<endl;
        int temp = i;
        int index = 0;
        bool flag = false;
        map<char,int> record;
        vector<bool> exist(10, false);
        while(temp!=0)
        {
            int last = temp%16;
            if(last<10)
            {
                if(last == 0 && first.count(charVector[index])!=0)
                {
                    flag = true;
                    break;
                }

                if(exist[last])
                {
                    flag = true;
                    break;
                }
                exist[last] = true;
                record[charVector[index]] = last;
            }
            temp /= 16;
            index++;
        }
        if(flag)
        {
            continue;
        }
        if(record.size()!=charSet.size())
        {
            continue;
        }
        if(findSolution(words, result, record))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<string> words={"IT","IT"};
    string result = "HE";
    //cout<<result<<endl;
    // vector<string> words = {"SIX","SEVEN","SEVEN"};
    // string result = "TWENTY";
    // vector<string> words = {"THIS","IS","TOO"};
    // string result = "FUNNY";
    cout<<(isSolvable(words, result)?"true":"false")<<endl;
    return 0;
}