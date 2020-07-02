#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int mincostTickets(vector<int>& days, vector<int>& costs) {
    int len = days.back();
    vector<int> dp(len+1, 0);
    int index = 0;
    for(int i=1;i<=len;i++){
        if(i == days[index]){
            int oneDayAgo = i-1;
            int sevenDaysAgo = max(0, i-7);
            int thirtyDaysAgo = max(0, i-30);

            dp[i] = min(costs[0] + dp[oneDayAgo], min(costs[1]+dp[sevenDaysAgo], costs[2]+dp[thirtyDaysAgo]));

            index++;
        }else{
            dp[i] = dp[i-1];
        }
    }
    return dp.back();  
}

int main(){
    // vector<int> days = {1,4,6,7,8,20};
    // vector<int> costs = {2,7,15};
    vector<int> days = {1,2,3,4,5,6,7,8,9,10,30,31};
    vector<int> costs = {2,7,15};
    cout<<mincostTickets(days, costs)<<endl;
}