#include<map>
#include<vector>
#include<iostream>

using namespace std;

//骑士跳“日”
long M = 1e9 + 7;
int knightDialer(int N) {
    //N等于1，即只有一步时
    if(N == 1){
        return 10;
    }

    //存储最终结果的vetor
    vector<long> dp1(10, 1);
    vector<long> dp2(10, 0);
    int step = 1;
    while(step<N){

        //dp2记录中间结果，dp2[i] 可以由dp1[j]、dp1[k]等得到
        dp2[1] = (dp1[6] + dp1[8])%M;
        dp2[2] = (dp1[7] + dp1[9])%M;
        dp2[3] = (dp1[4] + dp1[8])%M;
        dp2[4] = (dp1[0] + dp1[3] + dp1[9])%M;
        dp2[6] = (dp1[0] + dp1[1] + dp1[7])%M;
        dp2[7] = (dp1[2] + dp1[6])%M;
        dp2[8] = (dp1[1] + dp1[3])%M;
        dp2[9] = (dp1[2] + dp1[4])%M;
        dp2[0] = (dp1[4] + dp1[6])%M;
        dp1 = dp2;
        step++;
    }

    int result = 0;
    for(int i=0;i<dp1.size();i++){
        if(dp1[i] != 0){
            result = (result + dp1[i])%M;
        }
    }
    return result;
}

int main(){
    int resultValue = knightDialer(161);
    cout<<resultValue<<endl;
    return 0;
}