#include<iostream>
#include<vector>

/*
1330. 翻转子数组得到最大的数组值
给你一个整数数组 nums 。「数组值」定义为所有满足 0 <= i < nums.length-1 的 |nums[i]-nums[i+1]| 的和。

你可以选择给定数组的任意子数组，并将该子数组翻转。但你只能执行这个操作 一次 。

请你找到可行的最大 数组值 。
思路：参考 https://leetcode-cn.com/problems/reverse-subarray-to-maximize-array-value/solution/tan-xin-suan-fa-onshi-jian-fu-za-du-o1kong-jian-fu/

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

    int low = INT_MIN;
    int high = INT_MAX;
    int diff1 = INT_MIN;
    int diff2 = INT_MIN;
    for(int i=0;i<len-1;i++)
    {
        low = max(low, min(nums[i], nums[i+1]));
        high = min(high, max(nums[i], nums[i+1]));

        diff1 = max(diff1, abs(nums[i+1]-nums[0])-abs(nums[i+1]-nums[i]));
        diff2 = max(diff2, abs(nums[len-1]-nums[i])-abs(nums[i+1]-nums[i]));

    }
    int result = max(total+2*(low-high), max(total+diff1, total+diff2));
    return result;
}


int main()
{
    vector<int> nums = {2,3,1,5,4};
    cout<<maxValueAfterReverse(nums)<<endl;
    return 0;
}