#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int rob(vector<int>& nums) {
    if(nums.empty()){
        return 0;
    }

    int len = nums.size();
    vector<int> dp(len + 1, 0);

    for(int i=1;i<=len;i++){
        dp[i] = max(dp[i-1],  nums[i-1] + (i-2>0?dp[i-2]:dp[0]));
    }
    return dp[len];
}