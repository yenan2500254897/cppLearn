#include<iostream>
#include<vector>
using namespace std;
/*
1359. 有效的快递序列数目
给你 n 笔订单，每笔订单都需要快递服务。

请你统计所有有效的 收件/配送 序列的数目，确保第 i 个物品的配送服务 delivery(i) 总是在其收件服务 pickup(i) 之后。

由于答案可能很大，请返回答案对 10^9 + 7 取余的结果。

来源：力扣（LeetCode）
*/
int M = 1000000007;
// int countOrders(int n) {
//     if(n<=1){
//         return n;
//     }

//     int result = 0;
//     for(int i=0;i<n;i++){
//         int temp = countOrders(n-1);
//         for(int j=0;j<temp;j++){
//             result += (2*n-1);
//             result %= M;
//         }
//     }
//     return result;
// }
int countOrders(int n) {

    if(n==1){
        return 1;
    }
    int result = 1;
    for(int i=2;i<=n;i++){
        result = (long long) result * i%M * (2*i-1)%M;
    }
    return result;
}

int main(){
    int n = 2;
    cout<<countOrders(n)<<endl;
    return 0;
}