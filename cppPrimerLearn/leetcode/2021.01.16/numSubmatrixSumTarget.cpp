#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

/*
1074. 元素和为目标值的子矩阵数量
给出矩阵 matrix 和目标值 target，返回元素总和等于目标值的非空子矩阵的数量。

子矩阵 x1, y1, x2, y2 是满足 x1 <= x <= x2 且 y1 <= y <= y2 的所有单元 matrix[x][y] 的集合。

如果 (x1, y1, x2, y2) 和 (x1', y1', x2', y2') 两个子矩阵中部分坐标不同（如：x1 != x1'），那么这两个子矩阵也不同。

来源：力扣（LeetCode）
*/
using namespace std;

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
{
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> cuboid(row, vector<int>(col, 0));
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(i==0)
            {
                cuboid[i][j] = accumulate(matrix[0].begin(), matrix[0].begin()+j+1, 0);
            }
            else
            {
                cuboid[i][j] = cuboid[i-1][j] + accumulate(matrix[i].begin(), matrix[i].begin()+j+1, 0); 
            }
            //cout<<"i:="<<i<<"  j:="<<j<<"  value:="<<cuboid[i][j]<<endl;
        }
    }

    int result = 0;
    //cout<<"before: result:="<<result<<endl;
    for(int m=0;m<row;m++)
    {
        for(int n=0;n<col;n++)
        {
            for(int r=m;r<row;r++)
            {
                for(int c=n;c<col;c++)
                {
                    int value = cuboid[r][c];
                    if(m-1>=0 && n-1>=0)
                    {
                        value += cuboid[m-1][n-1];
                    } 
                    if(m-1>=0)
                    {
                        value -=cuboid[m-1][c];
                    }
                    if(n-1>=0)
                    {
                        value -=cuboid[r][n-1];
                    }
                    if(value == target)
                    {
                        result++;
                        //cout<<"m:="<<m<<"  n:="<<n<<"  r:="<<r<<"  c:="<<c<<"   value:=" <<value<<endl;
                    }
                }
            }
        }
    }
    return result;
}

int main()
{
    // vector<vector<int>> matrix = {{0,1,0},{1,1,1},{0,1,0}};
    // int target = 0;
    vector<vector<int>> matrix = {{0,0,0,1,1},{1,1,1,1,1},{0,1,0,0,0},{0,1,0,0,0},{1,1,1,1,0},{1,1,1,0,1}};
    int target = 0;
    cout<<numSubmatrixSumTarget(matrix, target)<<endl;
    return 0;
}