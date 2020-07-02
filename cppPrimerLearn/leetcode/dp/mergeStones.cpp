#include<iostream>
#include<vector>
#include<numeric>
#include<map>
#include<algorithm>

using namespace std;

int find_solution(vector<int>& stones, int K){
    int len = stones.size();
    if(len == K){
        return accumulate(stones.begin(), stones.end(), 0);
    }

    int value = INT_MAX;
    for(int i=0;i<=len-K;i++){
        int cost = accumulate(stones.begin()+i, stones.begin()+i+K, 0);
        vector<int> nextStones(stones.begin(), stones.begin()+i);
        nextStones.push_back(cost);
        nextStones.insert(nextStones.end(), stones.begin()+i+K, stones.end());
        int nextNeed = find_solution(nextStones, K);
        value = min(value, cost+nextNeed);
    }
    return value;
}

int mergeStones(vector<int>& stones, int K) {
    int len = stones.size();
    if(len == 1){
        return 0;
    }
    if(len<K || (K!=2 && len%(K-1) != 1)){
        return -1;
    }
    return find_solution(stones, K);
}


int mergeStonesSec(vector<int>& stones, int K) {
    int len = stones.size();
    if(len == 1){
        return 0;
    }
    if(len<K || (K!=2 && len%(K-1) != 1)){
        return -1;
    }
    
    vector<vector<int>> dp(len, vector<int>(len, 0));
    vector<int> prefixTotal(len+1, 0);
    for(int i=1;i<=len;i++){
        prefixTotal[i] = prefixTotal[i-1]+stones[i-1];
    }

    for(int r=0;r<len;r++){
        for(int l=r-K+1;l>=0;l--){

            int minValue = INT_MAX;
            for(int m=r;m>l;m -= (K-1)){
                minValue = min(minValue, dp[m][r] + dp[l][m-1]);
            }

            dp[l][r] = minValue;

            if((r-l)%(K-1) == 0){
                dp[l][r] += prefixTotal[r+1]-prefixTotal[l];
            }
        }
    }
    return dp[0][len-1];

}

int main(){
    vector<int> stones = {3,5,1,2,6};
    int K = 3;
    // vector<int> stones = {3,2,4,1};
    // int K = 2;
    cout<<mergeStonesSec(stones, K)<<endl;
}
