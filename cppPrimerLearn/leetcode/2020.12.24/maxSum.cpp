#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int limit = 1000000007;
int maxSum(vector<int>& nums1, vector<int>& nums2) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    vector<vector<int>> merge;
    merge.reserve(2*(len1+len2));
    for(int i=0;i<nums1.size();i++)
    {
        vector<int> temp = {nums1[i], 0};
        merge.push_back(temp);
    }

    for(int i=0;i<nums2.size();i++)
    {
        vector<int> temp = {nums2[i], 1};
        merge.push_back(temp);
    }
    sort(merge.begin(), merge.end(), [&](vector<int>& pre, vector<int> & next)
    {
        return pre[0]<next[0] || (pre[0] == next[0] && pre[1]<next[1]);
    });

    vector<long> dp(merge.size(), 0);
    long result = 0;
    for(int i=0;i<merge.size();i++)
    {
        if(i==0)
        {
            dp[i] = merge[i][0];
            result = dp[i];
            continue;
        }

        int pre = i-1;
        int preType = merge[pre][1];

        while(pre>=0 && preType != merge[i][1])
        {
            if(pre-1>=0)
            {
                preType = merge[pre-1][1];
            }
            pre--;
        }
        if(pre<0)
        {
            dp[i] = merge[i][0];
        }
        else
        {
            dp[i] = (dp[pre] + merge[i][0]);
        }

        if(merge[i-1][0] == merge[i][0])
        {
            dp[i] = max(dp[i], dp[i-1]);
            dp[i-1] = max(dp[i], dp[i-1]);
        }
        result = max(result, dp[i]);
    }
    //int result = *max_element(dp.begin(), dp.end());
    return result%limit;
}

int main()
{
    // vector<int> nums1 = {2,4,5,8,10};
    // vector<int> nums2 = {4,6,8,9};

    vector<int> nums1 = {1,2,3,4,5};
    vector<int> nums2 = {6,7,8,9,10};
    cout<<maxSum(nums1, nums2)<<endl;
}