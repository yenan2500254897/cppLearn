#include<iostream>
#include<vector>
#include <cstring>
#include <map>
/*
1590. 使数组和能被 P 整除
给你一个正整数数组 nums，请你移除 最短 子数组（可以为 空），使得剩余元素的 和 能被 p 整除。 不允许 将整个数组都移除。

请你返回你需要移除的最短子数组的长度，如果无法满足题目要求，返回 -1 。

子数组 定义为原数组中连续的一组元素。

思路：首先对整个nums进行求和得到total，看total%p是否等于0.
如果remain = total%p不等于0，则需要求一个最短的子数组[l...r]满足该子数组之和对p取余等于total%p。
令dp[i]为nums[0]...nums[i-1]的和，temp = dp[i]%p,要得出nums[j...i]之和对p取余为remain，则必须dp[j]%p == (temp + p - remain)%p
来源：力扣（LeetCode）
*/
using namespace std;

// int minSubarray(vector<int>& nums, int p) 
// {
//     int len = nums.size();

//     int* record = new int[p]();

//     long long total = 0;
//     int remain = 0;
//     long long temp = 0;
//     for(int i=0;i<len;i++)
//     {
//         total += nums[i];
//         temp = total;
//         for(int j=0;j<=i;j++)
//         {
//             remain = temp%p;
//             //cout<<"j:="<<j << "  i:="<<i<<"  total:="<<temp<<"  remain:="<<remain<<endl;
//             if(remain != 0)
//             {
//                 if(record[remain] == 0 || i-j+1<record[remain])
//                 {
//                     record[remain] = i-j+1;
//                 }
//                 //record[remain] = min(record[remain], i-j+1);
//                 //cout<<"record["<<remain<<"]:="<<record[remain]<<endl;
//             }
//             temp -= nums[j];
//         }
//     }

//     remain = total%p;
//     if(remain == 0)
//     {
//         return 0;
//     }

//     if(total<p || record[remain] == len)
//     {
//         return -1;
//     }
//     return record[remain];
// }

int minSubarray(vector<int>& nums, int p) 
{
    long long total = 0;
    for(auto item:nums)
    {
        total += item;
    }

    if(total%p == 0)
    {
        return 0;
    }
    int remain = total%p;
    map<int,int> record;
    record[0] = 0;
    long long pre = 0;
    int len = nums.size();
    int result = len;
    for(int i=1;i<=len;i++)
    {
        pre+=nums[i-1];
        int temp = pre%p;
        int need = ((long long)temp + p -remain)%p;
        if(record.count(need) != 0)
        {
            result = min(result, i-record[need]);
        }
        record[temp] = i;
    }
    return result==len?-1:result;

}

int main()
{
    vector<int> nums = {3,1,4,2};
    int p = 6;
    // vector<int> nums = {6,3,5,2};
    // int p = 9;
    // vector<int> nums = {1,2,3};
    // int p = 7;
    // vector<int> nums = {1,2,3};
    // int p = 7;
    
    cout<<minSubarray(nums, p)<<endl;
    return 0;
}