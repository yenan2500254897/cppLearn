#include<iostream>
#include<vector>

/*
1685. 有序数组中差绝对值之和

给你一个 非递减 有序整数数组 nums 。

请你建立并返回一个整数数组 result，它跟 nums 长度相同，且result[i] 等于 nums[i] 与数组中所有其他元素差的绝对值之和。

换句话说， result[i] 等于 sum(|nums[i]-nums[j]|) ，其中 0 <= j < nums.length 且 j != i （下标从 0 开始）。
来源：力扣（LeetCode）

思路：首先计算出nums[0]和其他元素的插值之和result[0], 因为nums不递减的特性，result[j]相对result[i](j>i)相比，diff = nums[j]-[i],左边增加i个diff,右边减少len-j-1个diff。
*/
using namespace std;

vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
{
    int len = nums.size();
    vector<int> result(len, 0);

    //计算第一个值和其他值的插值之和
    for(int i=1;i<len;i++)
    {
        result[0] += (nums[i]-nums[0]);
    }
    cout<<"j:=0  value:="<<result[0]<<endl;

    for(int j=1;j<len;j++)
    {
        int diff = nums[j]-nums[j-1];
        int left = j-1;
        int right = len-j-1;
        result[j] = result[j-1] + left*diff - right*diff;
        cout<<"j:="<<j<<"  value:="<<result[j]<<endl;
    }
    return result;
}

int main()
{
    // vector<int> nums = {2,3,5};
    vector<int> nums = {1,4,6,8,10};
    getSumAbsoluteDifferences(nums);
    return 0;
}