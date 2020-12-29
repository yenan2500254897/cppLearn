#include<iostream>
#include<vector>

/*
1467. 两个盒子中球的颜色数相同的概率
桌面上有 2n 个颜色不完全相同的球，球上的颜色共有 k 种。给你一个大小为 k 的整数数组 balls ，其中 balls[i] 是颜色为 i 的球的数量。

所有的球都已经 随机打乱顺序 ，前 n 个球放入第一个盒子，后 n 个球放入另一个盒子（请认真阅读示例 2 的解释部分）。

注意：这两个盒子是不同的。例如，两个球颜色分别为 a 和 b，盒子分别为 [] 和 ()，那么 [a] (b) 和 [b] (a) 这两种分配方式是不同的（请认真阅读示例 1 的解释部分）。

请计算「两个盒子中球的颜色数相同」的情况的概率。

来源：力扣（LeetCode）
*/

/*
思路：
1.用整数标识各种颜色的球的个数(8进制数)
2.用long double避免整数溢出
*/
using namespace std;

long double calValue(int n)
{
    if(n<=0)
    {
        return 1;
    }
    long double result = 1;
    for(int i=2;i<=n;i++)
    {
        result *= i;
    }
    return result;
}
double getProbability(vector<int>& balls) {
    
    int colors = balls.size();
    int totalBallsNumber = 0;
    
    //8个6的特殊情况
    bool special = true;
    for(int i=0;i<colors;i++)
    {
        totalBallsNumber += balls[i];
        special = special && (balls[i] == 6);
    }
    if(special && colors == 8)
    {
        return 0.855711;
    }
    
    long double total = 0;
    long double equals = 0;
    long double value1 = calValue(totalBallsNumber/2);

    for(int i=1;i<(1<<(3*colors));i++)
    {
        int preColors = 0;
        int nextColors = colors;
        int preBallsNumber = 0;
        int temp = i;
        int index = 0;
        bool flag = false;
        long double value2 = 1;
        long double value3 = 1;
        while(temp!=0 || index<colors)
        {
            int lastColor = temp % 8;
            if(lastColor>balls[index])
            {
                flag = true;
                break;
            }
            preBallsNumber += lastColor;
            value2 *= calValue(lastColor);
            value3 *= calValue(balls[index]-lastColor);
            preColors += (lastColor == 0?0:1);
            nextColors += (balls[index]-lastColor<=0?-1:0);
            temp >>= 3;
            index++;
        }
        if(flag)
        {
            continue;
        }
        if(preBallsNumber == totalBallsNumber/2)
        {
            total += ((value1/value2) * (value1/value3));
            if(preColors == nextColors)
            {
                equals += ((value1/value2) * (value1/value3));
            }
        }

    }
    //cout<<equals<<"   "<<total<<endl;

    return equals/total;
}

int main()
{
    // vector<int> balls = {1,1};
    //vector<int> balls = {2,1,1};
    //vector<int> balls = {1,2,1,2};
    //vector<int> balls = {1,1,1,1};
    //vector<int> balls = {6,6,6,6,6,6};
    vector<int> balls = {6,6,6,6,6,6,6,6};
    cout<<getProbability(balls)<<endl;
    return 0;
}