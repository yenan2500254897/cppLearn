#include<iostream>
#include<vector>
#include<queue>

using namespace std;

double soupServings(int N) {
    
    int choice[4][2] = {{-4, 0}, {-3, -1},  {-2, -2}, {-1, -3}};
    N = N/25 + (N%25?1:0);
    if(N>=500){
        return 1.0;
    }

    vector<vector<double> > dp(N+1, vector<double>(N+1, 0));
    dp[0][0] = 0.5;
    for(int i=1;i<=N;i++){
        dp[0][i] = 1;
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){

            double tempTotal = 0.0;
            for(int k=0;k<sizeof(choice)/sizeof(choice[0]);k++){
                tempTotal += dp[max(i+choice[k][0], 0)][max(j+choice[k][1], 0)];
            }
            dp[i][j] = tempTotal/4;
        }
    }
    return dp[N][N];
}


//TODO:N较大时，会超时，原因中间很多计算过程未记录下来，导致大量重复计算
//TODO:尝试用记忆化+dp
int main(){
    // int N = 600;
     int N = 1;
    // int N = 50;
    //  int N = 100;
    // int N = 1000;
    cout<<"soupServings.cpp result:";
    cout<< soupServings(N)<<endl;
}