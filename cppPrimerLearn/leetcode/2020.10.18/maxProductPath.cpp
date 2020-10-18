#include<iostream>
#include<vector>
/*
1594. 矩阵的最大非负积

给你一个大小为 rows x cols 的矩阵 grid 。最初，你位于左上角 (0, 0) ，每一步，你可以在矩阵中 向右 或 向下 移动。

在从左上角 (0, 0) 开始到右下角 (rows - 1, cols - 1) 结束的所有路径中，找出具有 最大非负积 的路径。路径的积是沿路径访问的单元格中所有整数的乘积。

返回 最大非负积 对 109 + 7 取余 的结果。如果最大积为负数，则返回 -1 。

注意，取余是在得到最大积之后执行的。

来源：力扣（LeetCode）
 */
using namespace std;

int maxProductPath(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<vector<long> > > result(row, vector<vector<long>>(col, vector<long>(2, INT_MIN)));
    result[0][0][0] = grid[0][0];
    result[0][0][1] = grid[0][0];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(i-1>=0){
                result[i][j][0] = min(grid[i][j]*result[i-1][j][0], grid[i][j]*result[i-1][j][1]);
                result[i][j][1] = max(grid[i][j]*result[i-1][j][0], grid[i][j]*result[i-1][j][1]);
            }
            if(j-1>=0){
                if(result[i][j][0] == INT_MIN){
                    result[i][j][0] = min(grid[i][j]*result[i][j-1][0], grid[i][j]*result[i][j-1][1]);
                }else{
                    result[i][j][0] = min(min(grid[i][j]*result[i][j-1][0], grid[i][j]*result[i][j-1][1]), result[i][j][0]);
                }
                
                if(result[i][j][0] == INT_MIN){
                    result[i][j][1] = max(grid[i][j]*result[i][j-1][0], grid[i][j]*result[i][j-1][1]);
                }else{
                    result[i][j][1] = max(max(grid[i][j]*result[i][j-1][0], grid[i][j]*result[i][j-1][1]), result[i][j][1]);
                }
                
            }
            
        }
    }
    if(result[row-1][col-1][1]<0){
        return -1;
    }
    return result[row-1][col-1][1]%1000000007;
}