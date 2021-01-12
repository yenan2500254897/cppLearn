#include<iostream>
#include<string>
#include<vector>

/*
1680. 连接连续二进制数字
给你一个整数 n ，请你将 1 到 n 的二进制表示连接起来，并返回连接结果对应的 十进制 数字对 109 + 7 取余的结果。

思路：难点在于怎么通过之前的数字对应的字符串快速推导出接下来的数字对应的字符串
规律：可以发现[pow(2,i)+1...pow(2,i+1))的整数对应的字符串可以由pow(2,i)对应的字符串和[pow(2, i-1), pow(2, i))拼接而来
特殊的是当为2的整数次方时，由pow(2, i)对应的字符和"0"拼接而来。

改进：不用字符串，直接可以进行数值的相加。
*/
using namespace std;
int concatenatedBinary(int n) 
{
    vector<int> record(1,1);
    while(record.back()<=n)
    {
        record.push_back(record.back()*2);
    }

    int len = 1;
    int result = 1;
    int mod=1e9+7;
    for(int i=2;i<=n;i++)
    {
        if(i == record[len])
        {
            len++;
        }
        result = (((long long)result<<len) + i)%mod;
    }

    return result;
}

int main()
{
    int n =3;
    cout<<concatenatedBinary(n)<<endl;
    return 0;
}