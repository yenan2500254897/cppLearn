#include<iostream>
#include<vector>

using namespace std;


int father[];
void init(){
    father = new int[20010];
    for(int i=0;i<20010;i++){
        father[i] = i;
    }
}

int findFather(int x){
    return x=father[x]?x:find(father[x]);
}

void merge(int x, int y){
    father[findFather(y)] = findFather(x);
}
int removeStones(vector<vector<int>>& stones) {
    init();
    for(int i=0;i<stones.size();i++){
        merge(stones[i][0], stones[i][1]+10000);
    }
    vector<int> flag(20010, false);
    int total = 0;
    for(int i=0;i<stones.size();i++){
        if(flag[find(stones[i][0])] == false){
            total++;
            flag[find(stones[i][0])] = true;
        }
    }
    return stones.size() - total;

}