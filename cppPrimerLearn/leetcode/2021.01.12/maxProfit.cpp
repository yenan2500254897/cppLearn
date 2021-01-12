#include<iostream>
#include<vector>
#include<queue>
#include<map>

/*
1648. 销售价值减少的颜色球
你有一些球的库存 inventory ，里面包含着不同颜色的球。一个顾客想要 任意颜色 总数为 orders 的球。

这位顾客有一种特殊的方式衡量球的价值：每个球的价值是目前剩下的 同色球 的数目。比方说还剩下 6 个黄球，那么顾客买第一个黄球的时候该黄球的价值为 6 。这笔交易以后，只剩下 5 个黄球了，所以下一个黄球的价值为 5 （也就是球的价值随着顾客购买同色球是递减的）

给你整数数组 inventory ，其中 inventory[i] 表示第 i 种颜色球一开始的数目。同时给你整数 orders ，表示顾客总共想买的球数目。你可以按照 任意顺序 卖球。

请你返回卖了 orders 个球以后 最大 总价值之和。由于答案可能会很大，请你返回答案对 109 + 7 取余数 的结果。
思路：利用map记录不同数量的球的个数（key为球的数量，value为该数量的球有多少种），用优先级队列assistant计算不同数量的球的数目。
asstant[i]表示某种颜色的球数量为i，i<j,assistant[i]>assistant[j], 从[assistant[i]...降序..assistant[j]+1]中间存在assintant[i]-assistant[j]种球的数量方案，
且每种方案有map[assintant[i]]种颜色可以选，接下来就是类似于二分查找了。


来源：力扣（LeetCode）
*/
using namespace std;

int maxProfit(vector<int>& inventory, int orders) 
{
    map<int, int> record;
    priority_queue<int> assistant;

    for(auto number:inventory)
    {
        if(record.count(number) == 0)
        {
            assistant.push(number);
            record[number] = 1;
        }
        else
        {
            record[number] += 1;
        }
    }
    assistant.push(0);

    int index = 0;
    int result = 0;
    int mod = 1e9+7;
    int curValue = assistant.top();
    int curCount = record[curValue];
    long long temp = 0;
    assistant.pop();
    while(index < orders)
    {
        if((long long)curCount*(curValue-assistant.top()) + index<=orders)
        {
            temp = ((long long)curValue + assistant.top()+1) * (curValue - assistant.top())/2;
            temp *= curCount;
            index += curCount*(curValue-assistant.top());
            curValue = assistant.top();
            assistant.pop();
            curCount += record[curValue];
        }
        else
        {
            int value = (orders-index)/curCount;
            int remain = (orders-index)%curCount;
            temp = ((long long)curValue + curValue-value+1) * value/2;
            temp *= curCount;
            temp += (long long)remain*(curValue-value);
            index = orders;
        }
        result = ((long long)result+temp)%mod;
        
    }
    return result;

}

int main()
{
    // vector<int> inventory = {3,5};
    // int orders = 6;
    vector<int> inventory = {100000000};
    int orders = 100000000;
    cout<<maxProfit(inventory, orders)<<endl;
    return 0;
}