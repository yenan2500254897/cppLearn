#include<iostream>
#include<math.h>
using namespace std;

int countDigitOne(int n) {
    if(n<10){
        return n>=1?1:0;
    }

    long dp[10] = {0};
    dp[1] = 1;
    for(int i=2;i<=9;i++){
        dp[i] = 10*dp[i-1] + pow(10, i-1);
    }

    int m = n;
    int value = 0;
    while (m/10 != 0)
    {
        m = m/10;
        value++;
    }
    
    int total = 0;
    total += m*dp[value];
    if(m == 1){
        total += (n - m*pow(10, value) +1);
    }else{
        total += pow(10, value);
    }

    return total+countDigitOne(n-m*pow(10, value));

}

int main(){
    // int n = 10;
    // int n = 11;
    int n = 101;
    // int n =20;
    cout<<countDigitOne(n)<<endl;
}