#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;

// int minReorder(int n, vector<vector<int>>& connections) {
//     vector<vector<int>> conn_idx(n, vector<int>());
//     for (int i = 0; i < connections.size(); i++) {
//         conn_idx[connections[i][0]].push_back(i);
//         conn_idx[connections[i][1]].push_back(i);
//     }

//     vector<bool> vi(connections.size(), false);
//     int ans = 0;

//     queue<int> que;
//     que.push(0);

//     while (!que.empty()) {
//         auto q = que.front();
//         que.pop();

//         for (auto idx : conn_idx[q]) {
//             if (vi[idx]) continue;
//             vi[idx] = true;

//             int a = connections[idx][0];
//             int b = connections[idx][1];

//             ans += (a == q);
//             a = (a == q) ? b : a;
//             que.push(a);
//         }
//     }

//     return ans;
// }

// int minReorder(int n, vector<vector<int>>& connections){
//     int len=connections.size();

//     map<int, set<int> > from;
//     map<int, set<int> > go;
//     // 查找速度有点慢
//     // map<vector<int>, int> visited;
//     vector<vector<bool> > visited(n, vector<bool>(n, false));

//     for(int i=0;i<len;i++){
//         int firstVal = connections[i][0];
//         int secondVal = connections[i][1];

//         if(from.count(secondVal)==0){
//             set<int> s1;
//             s1.insert(firstVal);
//             from[secondVal] = s1;
//         }else{
//             from[secondVal].insert(firstVal);
//         }

//         if(go.count(firstVal) == 0){
//             set<int> s2;
//             s2.insert(secondVal);
//             go[firstVal] = s2;
//         }else
//         {
//             go[firstVal].insert(secondVal);
//         }
//     }

//     queue<int> bfs;
//     bfs.push(0);
//     int result = 0;

//     while(!bfs.empty()){
//         int cur = bfs.front();
//         bfs.pop();


//         if(from.count(cur)>0){
//             for(int source:from[cur]){
//                 if(visited[source][cur] == false){
//                     visited[source][cur] = true;
//                     bfs.push(source);
//                 }
         
//             }
//             from.erase(cur);
//         }

//         if(go.count(cur)>0){
//             for(int dest:go[cur]){
//                 if(visited[cur][dest] == false){
//                     result++;
//                     visited[cur][dest] = true;
//                     bfs.push(dest);
//                 }
//             }
//             go.erase(cur);
//         }
//     }
//     return result;
// }

int minReorder(int n, vector<vector<int>>& connections){
    int len = connections.size();
    vector<vector<int> > record(n, vector<int>());
    for(int i=0;i<len;i++){
        record[connections[i][0]].push_back(i);
        record[connections[i][1]].push_back(i);
    }

    vector<bool> visited(len, false);
    queue<int> bfs;
    bfs.push(0);

    int result = 0;
    while (!bfs.empty())
    {
        int cur = bfs.front();
        bfs.pop();

        for(int id:record[cur]){
            int source = connections[id][0];
            int dest = connections[id][1];
            if(visited[id] == true){
                continue;
            }
            visited[id] = true;
            if(cur == source){
                result++;
                bfs.push(dest);
            }else{
                bfs.push(source);
            }
        }
    }
    return result;
    
}

int main(){
    int test[4][2] = {{0,1},{1,3},{2,3},{4,0}};
    int n =5;
    vector<vector<int> > vec(4,vector<int>(2, 0));
    vec[0][0] = 0;
    vec[0][1] = 1;
    vec[1][0] = 1;
    vec[1][1] = 3;
    vec[2][0] = 2;
    vec[2][1] = 3;
    vec[3][0] = 4;
    vec[3][1] = 0;
    cout<<"result:" << minReorder(n, vec);
}