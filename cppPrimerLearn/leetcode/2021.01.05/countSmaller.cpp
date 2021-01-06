#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>

/*
315. 计算右侧小于当前元素的个数
给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

解法：参考树状数组解法  https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/solution/shu-zhuang-shu-zu-de-xiang-xi-fen-xi-by-yangbingji/
来源：力扣（LeetCode）
*/
using namespace std;

// vector<int> countSmaller(vector<int>& nums) 
// {
//     priority_queue<int, vector<int>, greater<int>> visited;
//     priority_queue<int, vector<int>, greater<int>> assistant;

//     vector<int> result(nums.size(), 0);
//     if(nums.empty())
//     {
//         return result;
//     }

//     visited.push(nums.back());
//     for(int i=nums.size()-2;i>=0;i--)
//     {
//         assistant = visited;
//         while(!assistant.empty() && assistant.top()<nums[i])
//         {
//             assistant.pop();
//         }
//         result[i] = visited.size()-assistant.size();
//         visited.push(nums[i]);
//     }
//     return result;
// }

// vector<int> countSmaller(vector<int>& nums) 
// {
//     set<int> record;
//     for(auto item:nums)
//     {
//         record.insert(item);
//     }

//     vector<int> vec(record.size()+1, 0);
//     map<int, int> pos;
//     int index = 1;
//     for(auto value:record)
//     {
//         vec[index] = value;
//         pos[value] = index;
//         index++;
//     }

//     map<int, int> dp;
//     for(int i=1;i<=record.size();i++)
//     {
//         dp[i] = 0;
//     }
//     vector<int> result(nums.size(), 0);
//     for(int i=nums.size()-1;i>=0;i--)
//     {
//         result[i] = dp[pos[nums[i]]];
//         for(int j=pos[nums[i]]+1;j<=record.size();j++)
//         {
//             dp[j]++;
//         }   
//     }
//     return result;
// }

int lowBit(int i)
{
    return i&(-i);
}

int query(int i, vector<int>& C)
{
    int result = 0;
    while (i>0)
    {
        result += C[i];
        i -= lowBit(i);
    }
    return result;
}

void update(int i, int value, vector<int>& C)
{
    while(i<C.size())
    {
        C[i] += value;
        i += lowBit(i);
    }
}

vector<int> countSmaller(vector<int>& nums) 
{
    int len = nums.size();
    vector<int> result(len, 0);
    if(nums.empty())
    {
        return result;
    }

    set<int> numberSet;
    for(int item:nums)
    {
        numberSet.insert(item);
    }

    vector<int> record(numberSet.size()+1, 0);
    map<int, int> pos;
    int index = 1;
    for(auto item:numberSet)
    {
        record[index] = item;
        pos[item] = index;
        index++;
    }

    vector<int> C(numberSet.size()+1, 0);
    for(int j=len-1;j>=0;j--)
    {
        int p = pos[nums[j]];
        if(p-1>0)
        {
            result[j] = query(p-1, C);
        }
        update(p, 1, C);
    }
    return result;
}

int main()
{
    vector<int> nums = {5,2,6,1};
    vector<int> result = countSmaller(nums);
    for(auto item:result)
    {
        cout<<item<<"  ";
    }
    return 0;
}