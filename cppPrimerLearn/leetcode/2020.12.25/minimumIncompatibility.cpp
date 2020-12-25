#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<climits>

/*
1681. 最小不兼容性
给你一个整数数组 nums​​​ 和一个整数 k 。你需要将这个数组划分到 k 个相同大小的子集中，使得同一个子集里面没有两个相同的元素。

一个子集的 不兼容性 是该子集里面最大值和最小值的差。

请你返回将数组分成 k 个子集后，各子集 不兼容性 的 和 的 最小值 ，如果无法分成分成 k 个子集，返回 -1 。

子集的定义是数组中一些数字的集合，对数字顺序没有要求。

来源：力扣（LeetCode）
*/
using namespace std;

int minimumIncompatibility(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> dp(k+1, vector<int>(1<<nums.size(), INT_MAX));
    dp[0][0] = 0;

    int per = nums.size()/k;
    vector<vector<int>> accelerate((1<<nums.size()), vector<int>(3, 0));
    for(int i=1;i<(1<<nums.size());i++)
    {
        if(__builtin_popcount(i) == per)
        {
            set<int> assistant;
            int temp = i;
            int maxValue = 0;
            int minValue = INT_MAX;
            while(temp!=0)
            {
                int zero = __builtin_ctz(temp);
                if(assistant.count(nums[zero]) != 0)
                {
                    break;
                }
                assistant.insert(nums[zero]);
                maxValue = max(maxValue, nums[zero]);
                minValue = min(minValue, nums[zero]);
                temp ^= (1<<zero);
            }
            if(temp ==0)
            {
                accelerate[i][0] = 1;
                accelerate[i][1] = minValue;
                accelerate[i][2] = maxValue;
            }
        }
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<(1<<nums.size());j++)
        {
            if(__builtin_popcount(j)%per == 0){
                for(int cur = 1;cur<=j;cur++)
                {
                    if(__builtin_popcount(cur)==per && accelerate[cur][0]==1)
                    {
                        int pre = j^cur;
                        if(dp[i-1][pre] != INT_MAX)
                        {
                            dp[i][j] = min(dp[i][j], dp[i-1][pre]+accelerate[cur][2]-accelerate[cur][1]);
                        }
                    }
                }
            }
        }
    }

    int col = (1<<nums.size())-1;
    return dp[k][col] == INT_MAX?-1:dp[k][col];
}

int main()
{
    vector<int> nums = {7,3,16,15,1,13,1,2,14,5,3,10,6,2,7,15};
    int k = 8;
    // vector<int> nums = {1, 1};
    // int k = 1;
    cout<<minimumIncompatibility(nums, k)<<endl;
    return 0;
}