#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

double find_solution(vector<int>& A, int K, int left, vector<vector<double> >& dp){
    int right = A.size() - left;
    if(K<=0){
        return 0.0;
    }
    // cout<<"calculate left=: "<< left << " K=:" <<K<<endl;
    if(right == K || K==1){
        int divVal = (K == right? 1:A.size()-left);
        double total = accumulate(A.begin() + left, A.end(), 0.0) / divVal;
        dp[left][K] = total;
        // cout<<"dp["<<left<<"]"<<"["<<K<<"] = "<<dp[left][K]<<endl;
        return total;
    }

    if(dp[left][K] != 0.0){
        return dp[left][K];
    }

    for(int i=left;i<=left + right - K;i++){
        double currentValue = accumulate(A.begin()+left, A.begin()+i+1, 0.0)/(i-left+1);
        // cout<<"left=: "<<left<<" i:= "<<i<<" currentValue:=" <<currentValue<<endl;
        double nextValue = 0;
        if(dp[i+1][K-1] == 0.0){
            find_solution(A, K-1, i+1, dp);
        }
        nextValue = dp[i+1][K-1];
        dp[left][K] = max(dp[left][K], currentValue+nextValue);
    }
    // cout<<"dp["<<left<<"]"<<"["<<K<<"] = "<<dp[left][K]<<endl;
    return dp[left][K];
}

double largestSumOfAverages(vector<int>& A, int K) {
    int len = A.size();
    if(len<K){
        return 0.0;
    }

    if(len == K){
        return accumulate(A.begin(), A.end(), 0.0);
    }

    vector<vector<double> > dp(len+1, vector<double>(K+1, 0));
    return find_solution(A, K, 0, dp);
}

int main(){
    // vector<int> vec = {9,1,2,3,9};
    // int K = 3;
    vector<int> vec = {4,1,7,5,6,2,3};
    int K = 4;

    cout<<largestSumOfAverages(vec, K)<<endl;
}