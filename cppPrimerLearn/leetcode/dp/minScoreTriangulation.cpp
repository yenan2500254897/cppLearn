#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

// int minScoreTriangulation(vector<int>& A) {
//     if(A.size() == 3){
//         return A[0]*A[1]*A[2];
//     }

//     int len = A.size();
//     int left = 0;
//     int right = 0;

//     int ret = INT_MAX;
//     for(left = 0;left<len;left++){
//         for(right = left+2;right<len;right++){
//             if(right-left+1>=3 && len+left-right+1>=3){
//                 vector<int> leftVec(A.begin()+left, A.begin()+right+1);
//                 vector<int> rightVec(A.begin(), A.begin()+left+1);
//                 rightVec.insert(rightVec.end(), A.begin()+right, A.end());
//                 ret = min(ret, minScoreTriangulation(leftVec) + minScoreTriangulation(rightVec));
//             }
//         }
//     }
//     return ret;
// }

int minScoreTriangulation(vector<int>& A) {
    int len = A.size();
    vector<vector<int> > dp(len, vector<int>(len, 0)); 
    for(int i=len-3;i>=0;i--){
        for(int j=i+2;j<len;j++){
            for(int m=i+1;m<j;m++){
                if(dp[i][j] == 0){
                    dp[i][j] = dp[i][m] + A[i]*A[j]*A[m] + dp[m][j];
                }else
                {
                    dp[i][j] = min(dp[i][j], dp[i][m] + A[i]*A[j]*A[m] + dp[m][j]);
                }
                
            }
        }
    }
    return dp[0][len-1];

}

int main(){
    vector<int> test = {3,7,4,5};
    cout<<minScoreTriangulation(test)<<endl;
}