#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;

/*
1687. 从仓库到码头运输箱子
你有一辆货运卡车，你需要用这一辆车把一些箱子从仓库运送到码头。这辆卡车每次运输有 箱子数目的限制 和 总重量的限制 。

给你一个箱子数组 boxes 和三个整数 portsCount, maxBoxes 和 maxWeight ，其中 boxes[i] = [ports​​i​, weighti] 。

ports​​i 表示第 i 个箱子需要送达的码头， weightsi 是第 i 个箱子的重量。
portsCount 是码头的数目。
maxBoxes 和 maxWeight 分别是卡车每趟运输箱子数目和重量的限制。
箱子需要按照 数组顺序 运输，同时每次运输需要遵循以下步骤：

卡车从 boxes 队列中按顺序取出若干个箱子，但不能违反 maxBoxes 和 maxWeight 限制。
对于在卡车上的箱子，我们需要 按顺序 处理它们，卡车会通过 一趟行程 将最前面的箱子送到目的地码头并卸货。如果卡车已经在对应的码头，那么不需要 额外行程 ，箱子也会立马被卸货。
卡车上所有箱子都被卸货后，卡车需要 一趟行程 回到仓库，从箱子队列里再取出一些箱子。
卡车在将所有箱子运输并卸货后，最后必须回到仓库。

请你返回将所有箱子送到相应码头的 最少行程 次数。

来源：力扣（LeetCode）
*/

int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) 
{
    int len = boxes.size();
    vector<int> neg(len+1, 0);
    vector<long long> acc(len+1, 0);

    for(int i=0;i<len;i++)
    {
        neg[i+1] = ((i==0 || boxes[i][0] == boxes[i-1][0]) ? neg[i] : neg[i]+1);
        acc[i+1] = acc[i] + boxes[i][1];
    }

    vector<int> f(len+1, 0);
    vector<int> g(len+1, 0);
    deque<int> opt = {0};
    
    for(int i=1;i<=len;i++)
    {
        while(!opt.empty() && (i-opt.front()>maxBoxes || acc[i]-acc[opt.front()]>maxWeight))
        {
            opt.pop_front();
        }

        f[i] = g[opt.front()] + neg[i] + 2;

        if(i!=len)
        {
            g[i] = f[i] - neg[i+1];

            while(!opt.empty() && g[i]<=g[opt.back()])
            {
                opt.pop_back();
            }
            opt.push_back(i);
        }
    } 
    return f[len];
}

int main()
{
    vector<vector<int>> boxes = {{1,2},{3,3},{3,1},{3,1},{2,4}};
    int portsCount = 3;
    int maxBoxes = 3;
    int maxWeight = 6;
    cout<< boxDelivering(boxes, portsCount, maxBoxes, maxWeight)<<endl;
}