#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

/*
1449. 数位成本和为目标值的最大数字
给你一个整数数组 cost 和一个整数 target 。请你返回满足如下规则可以得到的 最大 整数：

给当前结果添加一个数位（i + 1）的成本为 cost[i] （cost 数组下标从 0 开始）。
总成本必须恰好等于 target 。
添加的数位中没有数字 0 。
由于答案可能会很大，请你以字符串形式返回。

如果按照上述要求无法得到任何整数，请你返回 "0" 。

来源：力扣（LeetCode）
思路：用dp[i]表示target=i时的最大数字,如果存在dp[i]的话，dp[i]必然是由max(dp[smaller] + dp[target-small], dp[target-small] + dp[smaller])，smaller<i
dp[0] = "";
*/

using namespace std;
string cmp(string pre, string next)
{
    if(pre == "0" || pre.size()<next.size() || (pre.size()==next.size() && pre<next))
    {
        return next;
    }
    return pre;
}
string findTarget(map<int, int>& record, vector<string>& dp, vector<bool>& visited, int target)
{

    if(dp[target] != "0" || visited[target])
    {
        //cout<<"target:="<<target<<"   str:="<<dp[target]<<endl;
        return dp[target];
    }


    for(auto cur:record)
    {
        if(cur.first<=target)
        {
            //cout<<cur.first<<"   "<<cur.second<<endl;
            string remain = findTarget(record, dp, visited, target-cur.first);
            if(remain!="0")
            {
                string temp = remain;
                remain.insert(remain.begin(), '0'+cur.second);
                temp.insert(temp.end(), '0'+cur.second);
                dp[target] = cmp(dp[target], cmp(temp, remain));
                //cout<<"target:="<<target<<"   str:="<<dp[target]<<endl;
            }

        }
    }
    visited[target] = true;
    cout<<"target:="<<target<<"   str:="<<dp[target]<<endl;
    return dp[target];
}

string largestNumber(vector<int>& cost, int target) 
{
    vector<string> dp(5001, "0");
    vector<bool> visited(5001, false);
    map<int, int> record;
    for(int i=0;i<cost.size();i++)
    {
        int value = cost[i];
        if(record.count(value) == 0 || record[value]<i+1)
        {
            record[value] = i+1;
        }
    }
    dp[0] = "";
    string result = findTarget(record, dp, visited, target);
    return result;

}

int main()
{
    // vector<int> cost = {4,3,2,5,6,7,2,5,5};
    // int target = 9;
    // vector<int> cost = {5,6,7,3,4,6,7,4,8};
    // int target = 29;
    vector<int> cost = {15,11,12,14,10,6,15,6,15};
    int target = 49;
    
    cout<<largestNumber(cost, target)<<endl;
    return 0;
}