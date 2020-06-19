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

//{1,3,7,9},{4,6},{2,8},{0}
int knightDialerSec(int N) {
    if(N == 1){
        return 10;
    }

    vector<long> dp1(4);
    //{1,3,7,9}有四个数
    dp1[0] = 4;
    //{4，6}有两个数
    dp1[1] = 2;
    //{2，8}有两个数
    dp1[2] = 2;
    //{0}有一个数
    dp1[3] = 1;
    vector<long> dp2(4);

    int step =1;
    while(step<N){
        //{1,3,7,9}可以由{4,6}和{2,8}得到，由于下一步只能选特定一个数，
        //但是实际可选的有两个，所以需要左移1位
        dp2[0] = ((dp1[1] + dp1[2])<<1)%M;
        //{4,6}可以由{1,3,7,9}移动一步得到，或者由{0}移动一步得到，
        //但是由{0}出发，有两种选择，所以需要左移1位
        dp2[1] = (dp1[0] + (dp1[3]<<1))%M;
        //{2，8}可以由{1,3,7,9}移动一步得到
        dp2[2] = (dp1[0])%M;
        //{0}可以由{4，6}移动一步得到
        dp2[3] = (dp1[1])%M;

        dp1 = dp2;
        step++;
    }

    long result = 0;
    for(int i=0;i<dp1.size();i++){
        result += dp1[i];
    }
    return result%M;
    
}
int main(){
    // int resultValue = knightDialer(161);
    int resultValue = knightDialerSec(161);
    cout<<resultValue<<endl;
    return 0;
}