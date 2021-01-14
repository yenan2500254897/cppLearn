#include<iostream>
#include<vector>
#include<map>
#include<set>

/*
1001. 网格照明
在 N x N 的网格 grid 上，每个单元格都有一盏灯，最初灯都处于 关闭 状态。

数组 lamps 表示打开的灯的位置。lamps[i] = [rowi, coli] 表示 打开 位于 grid[rowi][coli] 的第 i 盏灯 。每盏灯都照亮自身单元格以及同一行、同一列和两条对角线上的所有其他单元格。

查询数组 queries 中，第 i 次查询 queries[i] = [rowi, coli]，如果单元格 [rowi, coli] 是被照亮的，则查询结果为 1 ，否则为 0 。在第 i 次查询之后 [按照查询的顺序] ，关闭 位于单元格 grid[rowi][coli] 上或其相邻 8 个方向上（与单元格 grid[rowi][coli] 共享角或边）的任何灯。

返回答案数组 ans ， answer[i] 应等于第 i 次查询 queries[i] 的结果，1 表示照亮，0 表示未照亮。

来源：力扣（LeetCode）
*/
using namespace std;

long long cal(int row, int col, int N)
{
    return (long long)row*N + col;
}

bool isValid(int row, int col, int N, set<long long>& record)
{
    long long next = 0;
    //计算行
    for(int i=0;i<N;i++)
    {
        next = cal(row, i, N);
        if(record.count(next)!=0)
        {
            return true;
        }
    }

    //计算列
    for(int j=0;j<N;j++)
    {
        next = cal(j, col, N);
        if(record.count(next)!=0)
        {
            return true;
        }
    }

    //计算对角线
    for(int m=1;m<N;m++)
    {
        if(row-m>=0 && col-m>=0)
        {
            next = cal(row-m, col-m, N);
            if(record.count(next)!=0)
            {
                return true;
            }
        }
        if(row+m<N && col+m<N)
        {
            next = cal(row+m, col+m, N);
            if(record.count(next)!=0)
            {
                return true;
            }
        }
    }

    //计算反对角线
    for(int m=1;m<N;m++)
    {
        if(row-m>=0 && col+m<N)
        {
            next = cal(row-m, col+m, N);
            if(record.count(next)!=0)
            {
                return true;
            }
        }
        if(row+m<N && col-m>=0)
        {
            next = cal(row+m, col-m, N);
            if(record.count(next)!=0)
            {
                return true;
            }
        }
    }
    return false;
}

vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) 
{
    set<long long> record;
    for(auto item:lamps)
    {
        long long value = cal(item[0], item[1], N);
        //cout<<"insert:="<<value<<endl;
        record.insert(value);
    }

    vector<int> result(queries.size(), 0);
    for(int i=0;i<queries.size();i++)
    {
        int row = queries[i][0];
        int col = queries[i][1];
        if(isValid(row, col, N, record))
        {
            //cout<<"find row:="<<row<<" col:="<<col<<endl;
            result[i] = 1;
            //删除周围八个因为cur照亮的灯
            for(int r=-1;r<=1;r++)
            {
                for(int c=-1;c<=1;c++)
                {
                    int nextRow = row+r;
                    int nextCol = col+c;
                    if(nextRow>=0 && nextRow<N && nextCol>=0 && nextCol<N)
                    {
                        long long next = cal(nextRow, nextCol, N);
                        if(record.count(next)!=0)
                        {
                            record.erase(next);
                            //cout<<"erase row:="<<nextRow<<" col:="<<nextCol<<endl;
                        }
                    }
                }
            }
        }
    }
    return result;
}

int main()
{
    int N= 5;
    vector<vector<int>> lamps = {{0,0},{0,4}};
    vector<vector<int>> queries = {{0,4},{0,1},{1,4}};
    // int N= 5;
    // vector<vector<int>> lamps = {{0,0},{4,4}};
    // vector<vector<int>> queries = {{1,1},{1,1}};
    vector<int> result = gridIllumination(N, lamps, queries);
    for(auto item:result)
    {
        cout<<item<<"  ";
    }
    cout<<endl;
    return 0;
}