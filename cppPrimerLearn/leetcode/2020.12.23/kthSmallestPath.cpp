#include<iostream>
#include<vector>
#include<string>

/*
1643. 第 K 条最小指令
Bob 站在单元格 (0, 0) ，想要前往目的地 destination ：(row, column) 。他只能向 右 或向 下 走。你可以为 Bob 提供导航 指令 来帮助他到达目的地 destination 。

指令 用字符串表示，其中每个字符：

'H' ，意味着水平向右移动
'V' ，意味着竖直向下移动
能够为 Bob 导航到目的地 destination 的指令可以有多种，例如，如果目的地 destination 是 (2, 3)，"HHHVV" 和 "HVHVH" 都是有效 指令 。

然而，Bob 很挑剔。因为他的幸运数字是 k，他想要遵循 按字典序排列后的第 k 条最小指令 的导航前往目的地 destination 。k  的编号 从 1 开始 。

给你一个整数数组 destination 和一个整数 k ，请你返回可以为 Bob 提供前往目的地 destination 导航的 按字典序排列后的第 k 条最小指令 。

来源：力扣（LeetCode）
*/
using namespace std;

long long cal(int m, int n)
{
    if(m==0 || n==0)
    {
        return 1;
    }
    long long value1 = 1;
    long long value2 = 1;
    for(int i=0;i<n;i++)
    {
        value1 *= (m-i);
        value2 *= (i+1);
    }
    return value1 / value2;
    
}
string kthSmallestPath(vector<int>& destination, int k) {
    int row = destination[0];
    int col = destination[1];
    
    string result = "";
    int curR = 0;
    int curC = 0;
    while(curR<row || curC<col)
    {
        if(curR == row)
        {
            result.append(col-curC, 'H');
            break;
        }

        if(curC == col)
        {
            result.append(row-curR, 'V');
            break;
        }

        long long value = cal(row+col-curR-curC-1, col-curC-1);
        if(k <= value)
        {
            curC++;
            result.append("H");
        }
        else
        {
            k -= value;
            result.append("V");
            curR++;
        }
        
    }
    return result;

}

int main()
{
    vector<int> destination = {2, 3};
    int k=7;
    cout << kthSmallestPath(destination, k) <<endl;
}