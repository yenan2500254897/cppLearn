#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cstring>

/*
1224. 最大相等频率
给出一个正整数数组 nums，请你帮忙从该数组中找出能满足下面要求的 最长 前缀，并返回其长度：

从前缀中 删除一个 元素后，使得所剩下的每个数字的出现次数相同。
如果删除这个元素后没有剩余元素存在，仍可认为每个数字都具有相同的出现次数（也就是 0 次）。
能够满足答案的条件:
1、只有一种数字。如：1 1 1 1 1 
2、有多种数字，但每个数组只出现一次。 如：1 2 3 4 5
3、有多种数字，其中一种数字出现n+1次，其他出现n次。如：1 1 1 2 2 3 3 4 4
4、有多种数字，其中一种数字出现1次，其他出现n次。如：1 2 2 2 3 3 3 4 4 4

来源：力扣（LeetCode）
*/
using namespace std;
int maxEqualFreq(vector<int>& nums) 
{
    //记录数字i出现的次数
    int arr_a[100001];
    memset(arr_a, 0, 100001*sizeof(int));
    //记录出现i次的数字的个数
    int arr_b[100001];
    memset(arr_b, 0, 100001*sizeof(int));

    //记录出现的数字种类数
    int numbers = 0;
    //记录出现数字的最大频率
    int freq = 0;

    int result = 0;
    for(int i=0;i<nums.size();i++)
    {
        int value = nums[i];
        arr_a[value] += 1;
        arr_b[arr_a[value]] += 1;
        if(arr_a[value] == 1)
        {
            numbers++;
        }
        if(arr_a[value]>1)
        {
            arr_b[arr_a[value]-1] -= 1;
        }
        if(arr_a[value]>freq)
        {
            freq = arr_a[value];
        }

        if(arr_b[i+1] == 1 || arr_b[1]==i+1 || (arr_b[freq] == 1 && arr_b[freq-1]*(freq-1)+freq == i+1) 
        || (arr_b[1]==1 && arr_b[freq]*freq == i))
        {
            result = max(result, i+1);
        }
    }
    return result;
}

int main()
{
    // vector<int> nums = {2,2,1,1,5,3,3,5};
    //vector<int> nums = {1,1,1,2,2,2,3,3,3,4,4,4,5};
    // vector<int> nums = {1,1,1,2,2,2,3,3,3,4,4,4,5};
    vector<int> nums = {1,1,1,2,2,2};
    cout<<maxEqualFreq(nums)<<endl;
    return 0;
}