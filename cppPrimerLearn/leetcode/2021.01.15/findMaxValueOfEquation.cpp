#include<iostream>
#include<vector>
#include<set>
#include<map>

/*
1499. 满足不等式的最大值
给你一个数组 points 和一个整数 k 。数组中每个元素都表示二维平面上的点的坐标，并按照横坐标 x 的值从小到大排序。也就是说 points[i] = [xi, yi] ，并且在 1 <= i < j <= points.length 的前提下， xi < xj 总成立。

请你找出 yi + yj + |xi - xj| 的 最大值，其中 |xi - xj| <= k 且 1 <= i < j <= points.length。

题目测试数据保证至少存在一对能够满足 |xi - xj| <= k 的点。

来源：力扣（LeetCode）
*/
using namespace std;
int findMaxValueOfEquation(vector<vector<int>>& points, int k) 
{
    int len = points.size();
    int left = 0;
    int right = 0;
    int result = INT_MIN;
    while(left<len)
    {
        if(right+1<len && points[right+1][0]-points[left][0]<=k)
        {
            right++;
            continue;
        }

        //超时原因在这里，判断points[j][0]-points[i][0]+points[j][1]+points[i][1]的最大值时用的暴力法
        for(int i=left;i<right;i++)
        {
            for(int j=i+1;j<=right;j++)
            {
                result = max(result, points[j][0]-points[i][0]+points[j][1]+points[i][1]);
            }
        }
        if(points[left][0] == points[right][0])
        {
            left = right+1;
            right = left;
        }
        else
        {
            int temp = points[left][0];
            while(temp == points[left][0])
            {
                left++;
            }
        }
        
    }
    return result;
}

// int findMaxValueOfEquation(vector<vector<int>>& points, int k) 
// {
//     int result = INT_MIN;
//     map<int, int> dp;
//     dp[0] = points[0][1];
//     set<int> record;
//     record.insert(0);
//     for(int i=1;i<points.size();i++)
//     {
//         int diff = points[i][0]-points[i-1][0];
//         set<int> tempSet;
//         map<int, int> tempDp;
//         for(auto item:record)
//         {
//             if(item+diff<=k)
//             {
//                 result = max(result, points[i][1]+dp[item]+item+diff);

//                 tempDp[item+diff] = max(dp[item], points[i][1]);
//                 tempSet.insert(item+diff);
//             }
//         }

//         dp = tempDp;
//         record=tempSet;
//         if(record.empty())
//         {
//             dp[0] = points[i][1];
//             record.insert(0);
//         }
//         // for(auto item:tempSet)
//         // {
//         //     cout<<"i:="<<i<<"  value1:="<<item<<"  value2:="<<dp[item]<<endl;
//         // }
//     }
//     return result;
// }

int main()
{
    // vector<vector<int>> points = {{1,3},{2,0},{5,10},{6,-10}};
    // int k = 1;
    vector<vector<int>> points = {{-19,-12},{-13,-18},{-12,18},{-11,-8},
    {-8,2},{-7,12},{-5,16},{-3,9},{1,-7},{5,-4},
    {6,-20},{10,4},{16,4},{19,-9},{20,19}};
    int k = 6;

    cout<<findMaxValueOfEquation(points, k)<<endl;
    return 0;
}