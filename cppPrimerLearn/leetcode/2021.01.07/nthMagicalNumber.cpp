#include<iostream>
#include<set>
#include<vector>

/*
878. 第 N 个神奇数字
如果正整数可以被 A 或 B 整除，那么它是神奇的。

返回第 N 个神奇数字。由于答案可能非常大，返回它模 10^9 + 7 的结果。
思路：每a*b个数为一个循环，只需要算出[1...(a*b)]中有多少个数符合要求，且排好顺序即可，假设区间[1...(a*b)]满足的数的个数为len，
只需用n对len做除法和区域，算出第n个数在哪一个区间的第几个即可。
数学解法思路：
（1）求两个数的最大公约数与最小公倍数common。
（2）在[1...common]中神奇数字的数量number是确定的。
（3）利用n/number求出在第几个区间，n%number求出是该区间的第几个数
*/
using namespace std;

// int nthMagicalNumber(int n, int a, int b) 
// {
//     if(a>b)
//     {
//         int value = a;
//         a = b;
//         b = value;
//     }
//     if(n==1)
//     {
//         return a;
//     }

//     long limit = (long)a*(long)b;
//     set<long> record;
//     set<long> assistant;
//     record.insert(a);
//     record.insert(b);
//     assistant.insert(a);
//     assistant.insert(b);
//     set<long> temp;
//     while(!assistant.empty())
//     {
//         for(auto item:assistant)
//         {
//             int nextValue1 = item+a;
//             int nextValue2 = item+b;
//             if(nextValue1<=limit && record.count(nextValue1) == 0 && (nextValue1%a==0 || nextValue1%b==0))
//             {
//                 temp.insert(nextValue1);
//             }
//             if(nextValue2<=limit && record.count(nextValue2) == 0 && (nextValue2%a==0 || nextValue2%b==0))
//             {
//                 temp.insert(nextValue2);
//             }
//         }
//         record.insert(assistant.begin(), assistant.end());
//         assistant.swap(temp);
//         temp.clear();
//     }

//     long divisor = record.size();
//     long circleNumber = (n-1)/divisor;
//     long reserveNumber = (n-1)%divisor;

//     long result = 0;
//     result += circleNumber*limit;
//     vector<long> tempVec;
//     tempVec.insert(tempVec.end(), record.begin(), record.end());
//     result += tempVec[reserveNumber];
//     return result%1000000007;
// }

int gcd(int x, int y)
{
    if(x==0)
    {
        return y;
    }
    return gcd(y%x, x);
}

int nthMagicalNumber(int n, int a, int b) 
{
    long common = a*b/gcd(a, b);
    long number = common/a + common/b - 1;
    long circle = n/number;
    long remain = n%number;

    long result = 0;
    result += common*circle;
    if(remain!=0)
    {
        int temp[]={a, b};
        for(int i=0;i<remain-1;i++)
        {
            if(temp[0]<=temp[1])
            {
                temp[0] += a;
            }
            else
            {
                temp[1] += b;
            }
        }
        result += min(temp[0], temp[1]);
    }
    int mod = 1000000007;
    return int(result%mod);
}

int main()
{
    // int n=1;
    // int a=2;
    // int b=3;
    // int n=4;
    // int a=2;
    // int b=3;
    int n=5;
    int a=2;
    int b=4;
    // int n=3;
    // int a=6;
    // int b=4;
    cout<<nthMagicalNumber(n, a, b)<<endl;
    return 0;

}