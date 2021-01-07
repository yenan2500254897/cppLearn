#include<iostream>
#include<set>
#include<vector>

/*
878. 第 N 个神奇数字
如果正整数可以被 A 或 B 整除，那么它是神奇的。

返回第 N 个神奇数字。由于答案可能非常大，返回它模 10^9 + 7 的结果。
*/
using namespace std;

int nthMagicalNumber(int n, int a, int b) 
{
    if(a>b)
    {
        int value = a;
        a = b;
        b = value;
    }

    long limit = (long)a*(long)b;
    set<long> record;
    set<long> temp;
    int len = record.size();
    record.insert(a);
    record.insert(b);
    while(len!=record.size())
    {
        len = record.size();
        for(auto item:record)
        {
            int nextValue1 = item+a;
            int nextValue2 = item+b;
            if(nextValue1<=limit && record.count(nextValue1) == 0 && (nextValue1%a==0 || nextValue1%b==0))
            {
                temp.insert(nextValue1);
            }
            if(nextValue2<=limit && record.count(nextValue2) == 0 && (nextValue2%a==0 || nextValue2%b==0))
            {
                temp.insert(nextValue2);
            }
        }
        record.insert(temp.begin(), temp.end());
    }

    long divisor = record.size();
    long circleNumber = (n-1)/divisor;
    long reserveNumber = (n-1)%divisor;

    long result = 0;
    result += circleNumber*limit;
    vector<long> assistant;
    assistant.insert(assistant.end(), record.begin(), record.end());
    result += assistant[reserveNumber];
    return result%1000000007;
}

int main()
{
    // int n=1;
    // int a=2;
    // int b=3;
    // int n=4;
    // int a=2;
    // int b=3;
    // int n=5;
    // int a=2;
    // int b=4;
    int n=3;
    int a=6;
    int b=4;
    cout<<nthMagicalNumber(n, a, b)<<endl;
    return 0;

}