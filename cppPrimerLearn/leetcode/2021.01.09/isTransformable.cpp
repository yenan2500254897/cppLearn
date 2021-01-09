#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>

/*
1585. 检查字符串是否可以通过排序子字符串得到另一个字符串
给你两个字符串 s 和 t ，请你通过若干次以下操作将字符串 s 转化成字符串 t ：

选择 s 中一个 非空 子字符串并将它包含的字符就地 升序 排序。
比方说，对下划线所示的子字符串进行操作可以由 "14234" 得到 "12344" 。

如果可以将字符串 s 变成 t ，返回 true 。否则，返回 false 。

一个 子字符串 定义为一个字符串中连续的若干字符。

来源：力扣（LeetCode）

思路：
1.从头到尾去取t中的首个字母ch，让后去s中匹配第一个ch，如果找到对应的ch，从该位置往前找，是否存在比ch还小的，如果存在，直接放回false。
(因为ch总为t中的首个字母，因此s中如果有匹配的，则前面是不允许有比ch还小的存在的)
2.改进的点：不用find去s中查找ch的首个出现位置index，用vector<deque<int>> record, record[i] 记录了字母i出现的位置，index = record[i].front()
然后找比ch小的字母出现的索引是否比index小时，只用遍历record[j].front()(j<i)是否有比index小的情况。
*/
using namespace std;

// bool isTransformable(string s, string t) 
// {
//     if(s.size() != t.size())
//     {
//         return false;
//     }
    
//     int len = t.size();

//     for(int i=0;i<len;i++)
//     {
//         char cur = t[i];
        
//         int index = s.find(cur);
//         if(!(index>=0 && index<s.size()))
//         {
//             return false;
//         }
//         for(int i=0;i<index;i++)
//         {
//             if(s[i]<cur)
//             {
//                 return false;
//             }
//         }
//         s.erase(s.begin()+index);
//     }
//     return true;
// }

bool isTransformable(string s, string t) 
{
    if(s.size() != t.size())
    {
        return false;
    }
    
    vector<deque<int>> record(10,deque<int>(0, 0));
    for(int i=0;i<s.size();i++)
    {
        record[s[i]-'0'].push_back(i);
    }

    for(int j=0;j<t.size();j++)
    {
        char cur = t[j];
        
        if(record[cur-'0'].empty())
        {
            return false;
        }
        int index = record[cur-'0'].front();
        record[cur-'0'].pop_front();
        for(int k=cur-'0'-1;k>=0;k--)
        {
            if(!record[k].empty() && record[k].front()<index)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    // string s = "34521";
    // string t = "23415";
    // string s = "12345";
    // string t = "12435";

    string s = "84532";
    string t = "34852";
    
    string result = isTransformable(s, t)?"true":"false";
    cout<<result<<endl;
    return 0;
}