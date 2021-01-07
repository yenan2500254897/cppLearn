#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>

/*
1157. 子数组中占绝大多数的元素
实现一个 MajorityChecker 的类，它应该具有下述几个 API：

MajorityChecker(int[] arr) 会用给定的数组 arr 来构造一个 MajorityChecker 的实例。
int query(int left, int right, int threshold) 有这么几个参数：
0 <= left <= right < arr.length 表示数组 arr 的子数组的长度。
2 * threshold > right - left + 1，也就是说阈值 threshold 始终比子序列长度的一半还要大。
每次查询 query(...) 会返回在 arr[left], arr[left+1], ..., arr[right] 中至少出现阈值次数 threshold 的元素，如果不存在这样的元素，就返回 -1。

思路：树状数组，只是数组中存的不是各个值加的和，存的是一个vector,这个vector记录在arr中出现的数的出现次数。
来源：力扣（LeetCode）
*/
using namespace std;

void updateTree(int i, vector<int>& arr, map<int, int>& position, vector<vector<int>>& dp)
{
    int value = arr[i];
    int index = position[value];
    while(i<arr.size())
    {
        dp[i][index]++;
        i += (i&-i);
    }
}

vector<int> queryTree(int i, vector<vector<int>>& dp)
{
    vector<int> result(dp[0].size(), 0);
    vector<int> temp;
    while(i>0)
    {
        temp = dp[i];
        for(int i=0;i<temp.size();i++)
        {
            result[i]+=temp[i];
        }
        i -= (i&-i);
    }
    return result;
}

vector<vector<int>> dp;
map<int,int> values;
MajorityChecker(vector<int>& arr) 
{
    set<int> temp;
    temp.insert(arr.begin(), arr.end());
    map<int, int> position;
    int index = 1;
    for(auto item:temp)
    {
        position[item] = index;
        values[index] = item;
        index++;
    }
    arr.insert(arr.begin(), 0);
    dp.resize(arr.size(), vector<int>(temp.size()+1, 0));

    for(int i=1;i<arr.size();i++)
    {
        updateTree(i, arr, position, dp);
    }
}

// int query(int left, int right, int threshold) 
// {
//     map<int, int> temp;
    
//     for(int i=left;i<=right;i++)
//     {
//         int value = input[i];
//         if(temp.count(value) == 0)
//         {
//             temp[value] = 1;
//         }
//         else
//         {
//             temp[value]++;
//         }
//         if(temp[value]>=threshold)
//         {
//             return value;
//         }
//     }
//     return -1;
// }

int query(int left, int right, int threshold) 
{
    vector<int> result;
    left+=1;
    right+=1;
    if(left-1==0)
    {
        result = queryTree(right, dp);
    }
    else
    {
        vector<int> l=queryTree(left-1, dp);
        vector<int> r=queryTree(right, dp);
        result.resize(l.size(), 0);
        for(int i=0;i<l.size();i++)
        {
            result[i] = r[i]-l[i];
        }
    }
    for(int i=0;i<result.size();i++)
    {
        if(result[i]>=threshold)
        {
            return values[i];
        }
    }
    return -1;
    
}

int main()
{
    vector<int> arr = {1,1,2,2,1,1};
    MajorityChecker(arr);
    int left,right,threshold;
    // left = 0;
    // right = 5;
    // threshold = 4;
    left = 0;
    right = 5;
    threshold = 4;
    cout<<query(left, right, threshold)<<endl;
    return 0;
}