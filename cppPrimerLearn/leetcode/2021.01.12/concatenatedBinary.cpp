#include<iostream>
#include<string>
#include<vector>

/*
1680. 连接连续二进制数字
给你一个整数 n ，请你将 1 到 n 的二进制表示连接起来，并返回连接结果对应的 十进制 数字对 109 + 7 取余的结果。

思路：难点在于怎么通过之前的数字对应的字符串快速推导出接下来的数字对应的字符串
规律：可以发现[pow(2,i)+1...pow(2,i+1))的整数对应的字符串可以由pow(2,i)对应的字符串和[pow(2, i-1), pow(2, i))拼接而来
特殊的是当为2的整数次方时，由pow(2, i)对应的字符和"0"拼接而来。
*/
using namespace std;
int concatenatedBinary(int n) 
{
    vector<int> record(1,1);
    while(record.back()<=n)
    {
        record.push_back(record.back()*2);
    }

    vector<string> dp;
    dp.push_back("0");
    dp.push_back("1");

    string preStr = "1";
    string curStr = " ";
    int len = 1;
    int leftIndex = 0;
    for(int i=2;i<=n;i++)
    {
        if(i == record[len])
        {
            curStr = preStr + "0";
            preStr = curStr;
            len++;
            leftIndex = 1;
        }
        else
        {
            curStr = preStr.substr(0, preStr.size()-dp[leftIndex].size()) + dp[leftIndex];
            leftIndex++;
        }
        dp.push_back(curStr);
        // cout<<"i:="<<i<<"   curStr:="<<curStr<<endl;
    }

    int result = 0;
    int mod=1e9+7;
    for(string s:dp)
    {
        for(char ch:s)
        {
            result = ((long long)result*2 + (ch - '0'))%mod;
        }
    }
    return result;
}

int main()
{
    int n =3;
    cout<<concatenatedBinary(n)<<endl;
    return 0;
}