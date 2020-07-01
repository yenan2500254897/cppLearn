#include<iostream>
#include<vector>
using namespace std;

// long find_solution(int left, int d, int f, int target, vector<vector<long>>& dp){
//     if(left == d){
//         return (target>0 && target <= f)?1:0;
//     }
//     if(target < 0 || target>(d-left+1)*f){
//         return 0;
//     }
//     if(target == (d-left+1) || target==(d-left+1)*f){
//         return 1;
//     }

//     if(dp[left][target] != 0){
//         return dp[left][target];
//     }

//     long total = 0;
//     long M = 1000000007;
//     for(int leftValue = 1;leftValue<=f;leftValue++){
//         if(dp[left+1][target-leftValue] == 0){
//             find_solution(left+1, d, f, target-leftValue, dp);
//         }
//         if(target-leftValue>=0){
//             total += (dp[left+1][target-leftValue])%M;
//             total %= M;
//         }
//     }
//     dp[left][target] = total;
//     // cout<<"dp[" <<  left << "][" << target << "] := " << dp[left][target] <<endl;
//     return dp[left][target];
    
// }

// int numRollsToTarget(int d, int f, int target) {
//     //点数过小或者过大
//     if(target<d || target>d*f){
//         return 0;
//     }

//     //只有一个色子的情况,或者为边界值的情况
//     if(d == 1 || target == d || target == d*f){
//         return 1;
//     }

//     vector<vector<long> > dp(d+1, vector<long>(target+1, 0));
//     for(int i=1;i<=f;i++){
//         dp[d][i] = 1;
//     }
//     long total = 0;
//     long M = 1000000007;
//     for(int i = 1;i<=f;i++){
//         total += find_solution(2, d, f, target-i, dp);
//     }
//     cout<< total << endl;
//     return (int)(total%M);
    
// }

int numRollsToTarget(int d, int f, int target) {
    vector<vector<int> > dp(d+1, vector<int>(target+1, 0));
    const int mod = 1e9+7;
    dp[0][0] = 1;
    for(int i=1;i<=d;i++){
        for(int j=i;j<=target;j++){
            for(int k=1;k<=f && j-k>=0;k++){
                
                dp[i][j] += dp[i-1][j-k];
                dp[i][j] %= mod;
                
                
            }
        }
    }
    return dp[d][target];
}

int main(){
    int d=2;
    int f=6;
    int target =7;
    // int d=30;
    // int f=30;
    // int target =50;
    cout<<numRollsToTarget(d, f, target)<<endl;
}