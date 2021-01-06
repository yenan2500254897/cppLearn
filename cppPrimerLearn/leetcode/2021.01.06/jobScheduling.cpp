#include<iostream>
#include<vector>
#include<algorithm>

/*
1235. 规划兼职工作
你打算利用空闲时间来做兼职工作赚些零花钱。

这里有 n 份兼职工作，每份工作预计从 startTime[i] 开始到 endTime[i] 结束，报酬为 profit[i]。

给你一份兼职工作表，包含开始时间 startTime，结束时间 endTime 和预计报酬 profit 三个数组，请你计算并返回可以获得的最大报酬。

注意，时间上出现重叠的 2 份工作不能同时进行。

如果你选择的工作在时间 X 结束，那么你可以立刻进行在时间 X 开始的下一份工作。

来源：力扣（LeetCode）
*/
using namespace std;

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
{
    int len = startTime.size();
    vector<vector<int>> merge(len, vector<int>(3, 0));
    for(int i=0;i<len;i++)
    {
        merge[i][0] = startTime[i];
        merge[i][1] = endTime[i];
        merge[i][2] = profit[i];
    }
    sort(merge.begin(), merge.end(), [](vector<int>& pre, vector<int>& next)
    {
        return pre[0]<next[0] || (pre[0]==next[0] && pre[1]<=next[1]);
    });
    vector<int> dp(len, 0);

    for(int right=0;right<len;right++)
    {
        dp[right] = max(dp[right], merge[right][2]);
        for(int left = 0;left<right;left++)
        {
            if(merge[left][1]<=merge[right][0])
            {
                dp[right] = max(dp[right], dp[left]+merge[right][2]);
            }
        }
    }

    sort(dp.begin(), dp.end(), [](int& pre, int& next)
    {
        return pre>=next;
    });
    return dp.front();
}

int main()
{
    vector<int> startTime={1,2,3,3};
    vector<int> endTime={3,4,5,6};
    vector<int> profit={50,10,40,70};

    cout<<jobScheduling(startTime, endTime, profit)<<endl;
    return 0;
}