#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int numberOf2sInRange(int n) {
    if(n<=10){
        return n>=2?1:0;
    }

    long dp[10] = {0};
    dp[1] = 1;
    for(int i=2;i<=9;i++){
        dp[i] = 10*dp[i-1] + pow(10, i-1);
    }
    
    int m = n;
    int value = 0;
    while (m/10 !=0)
    {
        m/=10;
        value++;
    }

    int result = 0;
    result += m*dp[value];
    if(m == 2){
        result += n-m*pow(10, value)+1;
    }
    if(m > 2){
        result += pow(10, value);
    }
    return result + numberOf2sInRange(n-m*pow(10, value));
    
}

int main(){
    // int n = 25;
    int n = 225;
    cout<<numberOf2sInRange(n)<<endl;
}