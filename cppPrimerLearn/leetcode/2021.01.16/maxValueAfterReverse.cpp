#include<iostream>
#include<vector>

/*
1330. 翻转子数组得到最大的数组值
给你一个整数数组 nums 。「数组值」定义为所有满足 0 <= i < nums.length-1 的 |nums[i]-nums[i+1]| 的和。

你可以选择给定数组的任意子数组，并将该子数组翻转。但你只能执行这个操作 一次 。

请你找到可行的最大 数组值 。

来源：力扣（LeetCode）
*/
using namespace std;

int maxValueAfterReverse(vector<int>& nums) 
{
    int len = nums.size();
    int total = 0;
    for(int i=0;i<len-1;i++)
    {
        total += abs(nums[i]-nums[i+1]);
    }

    int diff = INT_MIN;
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            int value1=0;
            int value2=0;
            if(i-1>=0)
            {
                value1 += abs(nums[i-1]-nums[i]);
                value2 += abs(nums[i-1]-nums[j]);
            }
            if(j+1<len)
            {
                value1 += abs(nums[j+1]-nums[j]);
                value2 += abs(nums[j+1]-nums[i]);
            }
            diff = max(diff, value2-value1);
        }
    }
    return total+diff;
}

int main()
{
    vector<int> nums = {2,3,1,5,4};
    cout<<maxValueAfterReverse(nums)<<endl;
    return 0;
}