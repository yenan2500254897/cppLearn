#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int swimInWater(vector<vector<int>>& grid) {

    int N = grid.size();

    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int limit = N*N;
    vector<bool>visited(limit, false);
    deque<int> nodeQueue;
    nodeQueue.push_front(0);
    visited[0] = true;
    for(int waterHeight = grid[0][0];waterHeight<=limit;waterHeight++){
        // cout<<"waterHeight: "<<waterHeight<<endl;
        for(int id = 0;id<nodeQueue.size();id++){
            int cur = nodeQueue[id];
            if(cur == limit-1){
                return waterHeight;
            }
            int row = cur/N;
            int col = cur%N;
            // cout<<"row: "<<row<<" col: "<<col<<" val:"<<grid[row][col]<<endl;
            for(int i=0;i<4;i++){
                int nextR = row+dir[i][0];
                int nextC = col+dir[i][1];
                if(nextR>=0 & nextR<N && nextC>=0 && nextC<N){
                    int index = N*nextR+nextC;
                    if(visited[index] == false && grid[nextR][nextC]<=waterHeight){
                        // cout<<"add nextrow: "<<nextR<<" nextcol: "<<nextC<<" val:"<<grid[nextR][nextC]<<endl;
                        nodeQueue.push_back(index);
                        visited[index] = true;
                    }
                }
            }
        }
    }
    return limit-1;

}

int main(){
    // int N = 2;
    // int test[N][N] = {{0,2},{1,3}};
    // int N = 5;
    // int test[N][N] = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    // int N =2;
    // int test[N][N] = {{3,2},{0,1}};
    int N = 6;
    int test[N][N] = {{35,19,17,25,4,10},{8,18,29,21,28,31},{15,5,33,2,13,3},{26,20,27,23,11,1},{6,14,24,7,12,16},{30,34,32,22,0,9}};

    vector<vector<int> > vec(N);
    for(int i=0;i<N;i++){
        vector<int> temp(test[i], test[i]+N);
        vec[i] = temp;
    }
    cout<<swimInWater(vec)<<endl;
}