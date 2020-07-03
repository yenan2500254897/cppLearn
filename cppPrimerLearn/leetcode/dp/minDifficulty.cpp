#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

int minDifficulty(vector<int>& jobDifficulty, int d) {
    int len = jobDifficulty.size();
    //不可能的情况
    if(len<d){
        return -1;
    }
    
    vector<vector<vector<int>>> dp(len,vector<vector<int>>(len,vector<int>(d+1, -1)));

    for(int r=0;r<len;r++){
        for(int l=r;l>=0;l--){
            //k表示天数
            for(int k=1;k<=min(d, r-l+1);k++){
                //在一天干完
                if(k==1){
                    
                    dp[l][r][k] = *max_element(jobDifficulty.begin()+l, jobDifficulty.begin()+r+1);
                }else{
                    //需要一天以上时间干完
                    int minDiff = INT_MAX;
                    for(int m=r;m>l;m--){
                        //dp[m][r]需要n天完成
                        for(int n=1;n<k;n++){
                            if(dp[m][r][n]!=-1 && dp[l][m-1][k-n]!=-1){
                                minDiff = min(minDiff, dp[m][r][n]+dp[l][m-1][k-n]);
                            }
                        }
                    }
                    dp[l][r][k] = minDiff;
                }
            }
        }
    }
    return dp[0][len-1][d];

}

int minDifficultySec(vector<int>& jobDifficulty, int d) {
    int len = jobDifficulty.size();
    //不可能的情况
    if(len<d){
        return -1;
    }
    
    vector<vector<int>> dp(d+1,vector<int>(len+1, 0));
    vector<vector<int>> assistant(len,vector<int>(len, 0));

    for(int i=len-1;i>=0;i--){
        for(int j=i;j<len;j++){
            if(i==j){
                assistant[i][j] = jobDifficulty[i];
            }else{
                assistant[i][j] = max(assistant[i][j-1], jobDifficulty[j]);
            }
        }
    }

    for(int i=1;i<=d;i++){
        for(int j=i;j<=len;j++){
            if(i==1){
                dp[1][j] = assistant[0][j-1];
            }else{
                int value = INT_MAX;
                for(int m=i-1;m<j;m++){
                    value = min(value, dp[i-1][m] + assistant[m][j-1]);
                    
                }
                dp[i][j] = value;
            }
        }
    }
    return dp[d][len];
}

int main(){
    // vector<int> vec={6,5,4,3,2,1};
    // int d=2;
    // vector<int> vec={7,1,7,1,7,1};
    // int d=3;
    // vector<int> vec={1,1,1};
    // int d=3;

    vector<int> vec={186,398,479,206,885,423,805,112,925,656,16,932,740,292,671,360};
    int d = 4;
    cout<<minDifficultySec(vec, d)<<endl;
}