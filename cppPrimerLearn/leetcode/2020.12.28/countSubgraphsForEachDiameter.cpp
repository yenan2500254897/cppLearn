#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

/*
1617. 统计子树中城市之间最大距离
给你 n 个城市，编号为从 1 到 n 。同时给你一个大小为 n-1 的数组 edges ，其中 edges[i] = [ui, vi] 表示城市 ui 和 vi 之间有一条双向边。题目保证任意城市之间只有唯一的一条路径。换句话说，所有城市形成了一棵 树 。

一棵 子树 是城市的一个子集，且子集中任意城市之间可以通过子集中的其他城市和边到达。两个子树被认为不一样的条件是至少有一个城市在其中一棵子树中存在，但在另一棵子树中不存在。

对于 d 从 1 到 n-1 ，请你找到城市间 最大距离 恰好为 d 的所有子树数目。

请你返回一个大小为 n-1 的数组，其中第 d 个元素（下标从 1 开始）是城市间 最大距离 恰好等于 d 的子树数目。

请注意，两个城市间距离定义为它们之间需要经过的边的数目。

来源：力扣（LeetCode）
*/

/*
关键点：
1.一个子树的最大距离为其中任意两个点的距离的最大值
2.求任意两点间的最短距离----Floyed算法
3.状态压缩时，要判断该数字表示的子树是否合法----合法的子树(n个节点)有n-1条边
4.快速访问一个子树中的任意两个节点----参考64行和67行的两个判断条件
*/
using namespace std;

vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
    //求出任意两点间的最短距离
    vector<vector<int>> record(n, vector<int>(n, INT_MAX));
    for(int i=0;i<n;i++)
    {
        record[i][i] = 0;
    }
    for(auto item:edges)
    {
        record[item[0]-1][item[1]-1] = 1;
        record[item[1]-1][item[0]-1] = 1;
    }
    for(int mid = 0;mid<n;mid++)
    {
        for(int left = 0;left<n;left++)
        {
            for(int right = 0;right<n;right++)
            {
                if(record[left][mid] != INT_MAX && record[mid][right] != INT_MAX)
                {
                    record[left][right] = min(record[left][right], record[left][mid]+record[mid][right]);
                }
            }
        }
    }

    vector<int> dp((1<<n), 0);

    for(int nodes = 1;nodes<(1<<n);nodes++)
    {
        int countEdges = 0;
        //子树至少有两个节点
        if(__builtin_popcount(nodes)>=2)
        {
            for(int subNodes = nodes;subNodes;subNodes = ((subNodes-1)&nodes))
            {
                //cout<<"i: "<<nodes<<"   subNodes: "<< subNodes<<endl;
                if(__builtin_popcount(subNodes)==2)
                {
                    int temp = subNodes;
                    int lastOne = __builtin_ffs(temp)-1;
                    temp ^= (1<<lastOne);
                    int preOne = __builtin_ffs(temp)-1;
                    if(record[lastOne][preOne] != INT_MAX)
                    {
                        dp[nodes] = max(dp[nodes], record[lastOne][preOne]);
                    }
                    if(record[preOne][lastOne] == 1)
                    {
                        countEdges++;
                    }
                }
            }
            if(__builtin_popcount(nodes) != countEdges+1)
            {
                dp[nodes] = 0;
            }
        }
    }

    vector<int> result(n-1, 0);
    for(auto item:dp)
    {
        if(item != 0)
        {
            result[item-1]++;
        }
    }
    return result;
}

int main()
{
    // int n =4;
    // vector<vector<int>> edges =  {{1,2},{2,3},{2,4}};
    
    // int n =4;
    // vector<vector<int>> edges =  {{1,3},{1,4},{2,3}};
    int n = 7;
    vector<vector<int>> edges = {{1,4},{1,3},{2,5},{2,6},{3,6},{6,7}};
    vector<int> result = countSubgraphsForEachDiameter(n, edges);
    for(auto item:result)
    {
        cout<<item<<" ";
    }
    return 0;
}

