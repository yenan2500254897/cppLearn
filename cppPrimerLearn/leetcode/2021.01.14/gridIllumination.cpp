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

思路：
平行于x轴的线为 y=a,平行于y轴的线为 x=b,对角线和反对角线可以用x-y=c与x+y=d来表示。
*/
using namespace std;

long long cal(int row, int col, int N)
{
    long long result = (long long)row*N + col;
    return result;
}
vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) 
{
    map<int, set<long long>> rowRecord;
    map<int, set<long long>> colRecord;
    map<int, set<long long>> diagRecord;
    map<int, set<long long>> backdiagRecord;
    set<long long> exist;
    int row=0;
    int col=0;
    long long order=0;
    for(auto item:lamps)
    {
        row = item[0];
        col = item[1];
        order = cal(row, col, N);
        rowRecord[row].insert(order);
        colRecord[col].insert(order);
        backdiagRecord[row+col].insert(order);
        diagRecord[row-col].insert(order);
        exist.insert(order);
    }

    vector<int> result(queries.size(), 0);
    for(int i=0;i<queries.size();i++)
    {
        row = queries[i][0];
        col = queries[i][1];
        if((rowRecord.count(row) !=0 && !rowRecord[row].empty()) 
        || (colRecord.count(col) !=0 && !colRecord[col].empty())
        || (backdiagRecord.count(row+col) !=0 && !backdiagRecord[row+col].empty()) 
        || (diagRecord.count(row-col) !=0 && !diagRecord[row-col].empty()))
        {
            //cout<<"find row:="<<row<<" col:="<<col<<endl;
            result[i] = 1;
            //删除周围亮着的灯
            for(int r=-1;r<=1;r++)
            {
                for(int c=-1;c<=1;c++)
                {
                    int nextRow = row+r;
                    int nextCol = col+c;
                    //周围的灯的坐标要符合范围
                    if(nextRow>=0 && nextRow<N && nextCol>=0 && nextCol<N)
                    {
                        order = cal(nextRow, nextCol, N);
                        if(exist.count(order)!=0)
                        {
                            rowRecord[nextRow].erase(order);
                            colRecord[nextCol].erase(order);
                            backdiagRecord[nextRow+nextCol].erase(order);
                            diagRecord[nextRow-nextCol].erase(order);
                            exist.erase(order);
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