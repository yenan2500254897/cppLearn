#include<iostream>
#include<vector>
#include<map>
/*
1655. 分配重复整数
给你一个长度为 n 的整数数组 nums ，这个数组中至多有 50 个不同的值。同时你有 m 个顾客的订单 quantity ，其中，整数 quantity[i] 是第 i 位顾客订单的数目。请你判断是否能将 nums 中的整数分配给这些顾客，且满足：

第 i 位顾客 恰好 有 quantity[i] 个整数。
第 i 位顾客拿到的整数都是 相同的 。
每位顾客都满足上述两个要求。
如果你可以分配 nums 中的整数满足上面的要求，那么请返回 true ，否则返回 false 。

来源：力扣（LeetCode）
*/
using namespace std;

bool canDistribute(vector<int>& nums, vector<int>& quantity) {
  
    map<int, int> record;
    for(int item:nums)
    {
        record[item]++;
    }
    
    vector<int> assistant;
    for(auto it:record)
    {
        assistant.push_back(it.second);
    }

    vector<int> sum(1<<quantity.size(), 0);
    for(int i=0;i<(1<<quantity.size());i++)
    {
        for(int j=0;j<quantity.size();j++)
        {
            if((i & (1<<j)) != 0)
            {
                sum[i] = sum[i^(1<<j)] + quantity[j];
                break;
            }
        }
    }

    vector<vector<bool>> dp(assistant.size()+1, vector<bool>(1<<quantity.size(), false));
    for(int i=0;i<=assistant.size();i++)
    {
        dp[i][0] = true;
    } 

    for(int m=1;m<=assistant.size();m++)
    {
        for(int n=1;n<(1<<quantity.size());n++)
        {
            if(dp[m-1][n] == true)
            {
                dp[m][n] = true;
                continue;
            }

            for(int k=n;k!=0;k=(k-1)&n)
            {
                if(sum[k] <= assistant[m-1])
                {
                    dp[m][n] = dp[m][n] || dp[m-1][n-k];
                }
                if(dp[m][n])
                {
                    break;
                }
            }
        }
    }
    return dp[assistant.size()][(1<<quantity.size())-1];
}

int main()
{
    // vector<int> num = {1,1,2,3};
    // vector<int> quantity = {2,2};
    
    vector<int> num = {154,533,533,533,154,154,533,154,154};
    vector<int> quantity = {3, 2, 2, 2};

    //  vector<int> num = {1,2,3,4};
    // vector<int> quantity = {2};
    cout<< (canDistribute(num, quantity)? "true" : "false" ) <<endl;
}