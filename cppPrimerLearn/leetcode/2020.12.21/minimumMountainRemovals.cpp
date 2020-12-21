#include<iostream>
#include<vector>

/*
1671. 得到山形数组的最少删除次数

我们定义 arr 是 山形数组 当且仅当它满足：

arr.length >= 3
存在某个下标 i （从 0 开始） 满足 0 < i < arr.length - 1 且：
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
给你整数数组 nums​ ，请你返回将 nums 变成 山形状数组 的​ 最少 删除次数。

来源：力扣（LeetCode）
*/
using namespace std;

int minimumMountainRemovals(vector<int>& nums) {
    int len = nums.size();

    vector<int> leftResult(len+2, INT_MAX);
    vector<int> rightResult(len+2, INT_MAX);

    leftResult[0] = leftResult[len+1] = 0;
    rightResult[0] = rightResult[len+1] = 0;

    for(int i=1;i<=len;i++)
    {
        for(int left = i-1;left>=0;left--)
        {
            if(left == 0 || nums[i-1] > nums[left-1])
            {
                leftResult[i] = min(leftResult[i], leftResult[left]+i-left-1);
            }
        }
    }

    for(int i=len;i>=1;i--)
    {
        for(int right=len+1;right>=i+1;right--)
        {
            if(right == len+1 || nums[i-1]>nums[right-1])
            {
                rightResult[i] = min(rightResult[i], rightResult[right]+right-i-1);
            }
        }
    }

    int retValue = INT_MAX;
    for(int i=1;i<=len;i++)
    {
        if(leftResult[i]<i-1 && rightResult[i]<len-i)
        {
            retValue = min(retValue, leftResult[i]+rightResult[i]);
        }
    }
    return retValue;
}

int main()
{
    // vector<int> test = {2,1,1,5,6,2,3,1};
    vector<int> test = {100,92,89,77,74,66,64,66,64};
    cout<<minimumMountainRemovals(test)<<endl;
    return 0;
}