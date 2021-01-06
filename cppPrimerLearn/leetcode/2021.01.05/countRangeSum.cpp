#include<iostream>
#include<vector>
#include<algorithm>

/*
327. 区间和的个数
给定一个整数数组 nums，返回区间和在 [lower, upper] 之间的个数，包含 lower 和 upper。
区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。

说明:
最直观的算法复杂度是 O(n2) ，请在此基础上优化你的算法。

思路：将nums[i...j]分为nums[i...k]与nums[k+1...j]两个部分，分别求出nums[i...k]与nums[k+1...j]满足条件的区间数目，
然后求存在的sum(nums[n...k])+sum(nums[k+1...m])满足条件的区间数目。
来源：力扣（LeetCode）
*/
using namespace std;

// int findSolution(vector<int>& nums, int lower, int upper, int leftIndex, int rightIndex)
// {
//     if(leftIndex==rightIndex)
//     {
//         int temp = (nums[leftIndex]>=lower && nums[leftIndex]<=upper?1:0);
//         //cout<<"left:="<<leftIndex<<"  right:="<<rightIndex<<"   result:="<<result<<endl;
//         return temp;
//     }

//     int result = 0;
//     int mid = (leftIndex+rightIndex)/2;
//     result += findSolution(nums, lower, upper, leftIndex, mid);
//     result += findSolution(nums, lower, upper, mid+1, rightIndex);

//     vector<long> leftVector(mid-leftIndex+1,0);
//     leftVector[mid-leftIndex] = nums[mid];
//     for(int i=mid-1;i>=leftIndex;i--)
//     {
//         leftVector[i-leftIndex] = leftVector[i-leftIndex+1] + nums[i];
//     }

//     vector<long> rightVector(rightIndex-mid,0);
//     rightVector[0] = nums[mid+1];
//     for(int i=mid+2;i<=rightIndex;i++)
//     {
//         rightVector[i-mid-1] = rightVector[i-mid-2] + nums[i];
//     }

//     sort(leftVector.begin(), leftVector.end());
//     sort(rightVector.begin(), rightVector.end());

//     int l=0;
//     int r=rightVector.size()-1;
//     for(auto left:leftVector)
//     {
//         //剪枝，避免超时
//         if(left+rightVector.back()<lower || left+rightVector.front()>upper)
//         {
//             continue;
//         }

//         if(l==0)
//         {
//             while(l<rightVector.size() && left+rightVector[l]<lower)
//             {
//                 l++;
//             }
//         }
//         else
//         {
//             while(l-1>=0 && left+rightVector[l-1]>=lower)
//             {
//                 l--;
//             }
//         }

//         while(r>=0 && left+rightVector[r]>upper)
//         {
//             r--;
//         }
//         result += (r-l+1);
//     }
//     //cout<<"left:="<<leftIndex<<"  right:="<<rightIndex<<"   result:="<<result<<endl;
//     return result;
// }
// int countRangeSum(vector<int>& nums, int lower, int upper) 
// {
//     if(nums.empty())
//     {
//         return 0;
//     }
//     return findSolution(nums, lower, upper, 0, nums.size()-1);
// }

// int countRangeSum(vector<int>& nums, int lower, int upper) 
// {
//     if(nums.empty())
//     {
//         return 0;
//     }

//     vector<long> total(nums.size(), 0);
//     total[0] = nums[0];
//     for(int i=1;i<nums.size();i++)
//     {
//         total[i] = total[i-1]+nums[i];
//     }

//     int result = 0;
//     for(int i=0;i<nums.size();i++)
//     {
//         for(int j=i;j<nums.size();j++)
//         {
//             if(i-1>=0)
//             {
//                 total[j] -= nums[i-1];
//             }
//             if(total[j]>=lower && total[j]<=upper)
//             {
//                 result++;
//             }
//         }
//     }
//     return result;
// }

int lowBit(int i)
{
    return i&(-i);
}

long query(int i, vector<long>& C)
{
    long result = 0;
    while (i>0)
    {
        result += C[i];
        i -= lowBit(i);
    }
    return result;
}

void update(int i, int value, vector<long>& C)
{
    while(i<C.size())
    {
        C[i] += value;
        i += lowBit(i);
    }
}

int countRangeSum(vector<int>& nums, int lower, int upper) 
{
    if(nums.empty())
    {
        return 0;
    }
    int result = 0;
    nums.insert(nums.begin(), 0);
    vector<long> C(nums.size(), 0);
    vector<long> total(nums.size(), 0);
    for(int right=1;right<C.size();right++)
    {
        update(right, nums[right], C);
        long value = query(right, C);
        if(value>=lower && value<=upper)
        {
            result++;
        }
        total[right] = value;
        for(int left=1;left<right;left++)
        {
            long temp = total[left];
            if(value-temp>=lower && value-temp<=upper)
            {
                result++;
            }
        }
    }
    return result;
}

int main()
{
    // vector<int> nums = {-2,5,-1};
    // int lower = -2;
    // int upper = 2;

    vector<int> nums = {-2,0,1,-1};
    int lower = 1;
    int upper = 4;
    
    cout<<countRangeSum(nums, lower, upper)<<endl;
}