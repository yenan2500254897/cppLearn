#include<iostream>
#include<vector>
#include<queue>

/*
315. 计算右侧小于当前元素的个数
给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

来源：力扣（LeetCode）
*/
using namespace std;

vector<int> countSmaller(vector<int>& nums) {
    priority_queue<int, vector<int>, greater<int>> visited;
    priority_queue<int, vector<int>, greater<int>> assistant;

    vector<int> result(nums.size(), 0);
    if(nums.empty())
    {
        return result;
    }

    visited.push(nums.back());
    for(int i=nums.size()-2;i>=0;i--)
    {
        assistant = visited;
        while(!assistant.empty() && assistant.top()<nums[i])
        {
            assistant.pop();
        }
        result[i] = visited.size()-assistant.size();
        visited.push(nums[i]);
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