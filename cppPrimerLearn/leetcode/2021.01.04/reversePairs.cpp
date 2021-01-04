#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

/*
493. 翻转对 

给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。

你需要返回给定数组中的重要翻转对的数量。
*/
using namespace std;

int findSolution(vector<int>& nums, int leftIndex, int rightIndex)
{
    int result = 0;
    if(rightIndex==leftIndex)
    {
        return result;
    }
    result += findSolution(nums, leftIndex, (leftIndex+rightIndex)/2);
    result += findSolution(nums, (leftIndex+rightIndex)/2+1, rightIndex);
    int mid = (leftIndex+rightIndex)/2;
    sort(nums.begin()+leftIndex, nums.begin() + mid + 1);
    sort(nums.begin()+mid + 1, nums.begin()+rightIndex+1);
    int r = (leftIndex+rightIndex)/2+1;
    for(int l=leftIndex;l<=(leftIndex+rightIndex)/2;l++)
    {
        for(;r<=rightIndex;)
        {
            if((long)nums[l]>(long)nums[r]*2)
            {
                r++;
            }
            else
            {
                break;
            }
            
        }
        result+=(r-(leftIndex+rightIndex)/2-1);
    }
    //cout<<"left:=" << leftIndex<<"   right:="<<rightIndex<<"   result:="<<result<<endl;
    return result;
}
int reversePairs(vector<int>& nums) 
{
    if(nums.empty())
    {
        return 0;
    }
    return findSolution(nums, 0, nums.size()-1);
}

int main()
{
    vector<int> nums = {1,3,2,3,1};
    cout<<reversePairs(nums)<<endl;
    return 0;
}