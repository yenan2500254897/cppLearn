#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>

/*
1316. 不同的循环子字符串
给你一个字符串 text ，请你返回满足下述条件的 不同 非空子字符串的数目：

可以写成某个字符串与其自身相连接的形式（即，可以写为 a + a，其中 a 是某个字符串）。
例如，abcabc 就是 abc 和它自身连接形成的。

来源：力扣（LeetCode）
思路：用暴力法求解text[l...m]与text[m+1, r]是否相等，如果相等将text[l,r]插入set
优化的点：
(1)保证(r-l+1)%2==0
(2)使用string_view不产生新的string对象
string_view 是只读的轻量对象，它对所指向的字符串没有所有权。
string_view通常用于函数参数类型，可用来取代 const char* 和 const string&。
string_view 代替 const string&，可以避免不必要的内存分配。
string_view的成员函数即对外接口与 string 相类似，但只包含读取字符串内容的部分。
string_view::substr()的返回值类型是string_view，不产生新的字符串，不会进行内存分配。
(3)使用unordered_set减少扩容导致的时间
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

unordered_set<string_view> record;
int distinctEchoSubstrings(string text) 
{
    string_view text_v = text;
    int len = text_v.size();
    for(int right=1;right<len;right++)
    {
        for(int left=(right%2==0?1:0);left<right;left+=2)
        {
            int half = (right-left+1)/2;
            if(text_v.substr(left, half) == text_v.substr(left+half, half))
            {
                record.insert(text_v.substr(left, half*2));
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