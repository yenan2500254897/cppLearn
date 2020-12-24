#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>

/*
1483. 树节点的第 K 个祖先

给你一棵树，树上有 n 个节点，按从 0 到 n-1 编号。树以父节点数组的形式给出，其中 parent[i] 是节点 i 的父节点。树的根节点是编号为 0 的节点。

请你设计并实现 getKthAncestor(int node, int k) 函数，函数返回节点 node 的第 k 个祖先节点。如果不存在这样的祖先节点，返回 -1 。

树节点的第 k 个祖先节点是从该节点到根节点路径上的第 k 个节点。

来源：力扣（LeetCode）

*/
using namespace std;

//会超时，是因为计算了dp中的所有可能
class TreeAncestor
{
    vector<vector<int>> dp;
    int limit=0;
    TreeAncestor(int n, vector<int>& parent) 
    {
        limit = n;
        //初始化dp
        dp.resize(n, vector<int>(n+1, -1));
        for(int i=0;i<n;i++)
        {
            dp[i][0] = i;
        }

        //记录索引和父节点索引的对应关系
        map<int, set<int>> record;
        for(int i=1;i<parent.size();i++)
        {
            record[parent[i]].insert(i);
        }

        //层次遍历节点用
        deque<int> layer;
        layer.push_back(0);
        deque<int> assistant;
        while(!layer.empty())
        {
            int cur = layer.front();
            layer.pop_front();

            for(auto item:record[cur])
            {
                for(int i=0;i<=n;i++)
                {
                    if(dp[cur][i] >= 0)
                    {
                        dp[item][i+1] = dp[cur][i];
                    }
                }
                assistant.push_back(item);
            }

            if(layer.empty())
            {
                layer.swap(assistant);
                assistant.clear();
            }
            
        }

    }
        
    int getKthAncestor(int node, int k) 
    {
        return dp[node][k];
    }
}