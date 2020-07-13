#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int> > colorBorder(vector<vector<int> >& grid, int r0, int c0, int color) {
    int row = grid.size();
    int col = grid[0].size();
    //用于记录哪些位置被访问过
    vector<vector<bool> > visited(row, vector<bool>(col, false));
    //用于广度优先搜索
    queue<int*> assistant;
    //方向
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 

    //初始化
    int init[2] = {r0, c0};
    assistant.push(init);
    visited[r0][c0] = true;

    while(!assistant.empty()){
        int* cur = assistant.front();
        assistant.pop();

        int r = cur[0];
        int c = cur[1];

        int precolor = grid[r][c];
        cout<<"r:"<<r<<"  c:"<<c<<endl;
        if(r == 0 || r == row-1 || c==0 || c==col-1){
            cout<<"case 1 change "<<"r:"<<r<<"  c:"<<c<< " color: "<<color<<endl;
            grid[r][c] = color;
        }
        //不在边界，但是在联通分量的边界
        bool flag = true;
        for(int i=0;i<4;i++){
            int nextR = r+dir[i][0];
            int nextC = c+dir[i][1];

            //不在联通分量的边界
            if(nextR>=0 && nextR<row && nextC>=0 && nextC<col
            && visited[nextR][nextC] == false && precolor == grid[nextR][nextC]){
                cout<<"add r:"<<nextR<<"  c:"<<nextC<<endl;
                flag = false;
                visited[nextR][nextC] = true;
                int temp[2] = {nextR, nextC};
                assistant.push(temp);
            }
        }
        if(flag ){
            cout<<"case 2 change "<<"r:"<<r<<"  c:"<<c<< " color: "<<color<<endl;
            grid[r][c] = color;
        }
    }
    return grid;

}

int main(){
    int test[2][2] = {{1,1},{1,2}};
    int r0 = 0;
    int c0 = 0;
    int color = 3;
    
    vector<vector<int> > vec(2,vector<int>(2, 0));
    vec[0][0] = 1;
    vec[0][1] = 1;
    vec[1][0] = 1;
    vec[1][1] = 2;

    vector<vector<int> > result = colorBorder(vec, r0, c0, color);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<" "<<result[i][j]<<" ";
        }
        cout<<endl;
    }

}