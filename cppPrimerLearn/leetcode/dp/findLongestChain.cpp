#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(vector<int>& pre, vector<int>& next){
    return pre.back()<next.back()?true:(pre.back() == next.back() && pre.front()<next.front())?true:false;
}

// int findLongestChain(vector<vector<int>>& pairs) {   
//     int len = pairs.size();  
//     vector<int> dp(len, 0);

//     sort(pairs.begin(), pairs.end(), cmp);
//     dp[0] = 1;
//     for(int index = 1;index<len;index++){
//         for(int left = index-1;left>=0;left--){
//             if(pairs[left].back()<pairs[index].front() 
//             && dp[left]+1>dp[index]){
//                 dp[index] = dp[left]+1;
//             }
//         }
//     }
//     int ret = 0;
//     for(int i=0;i<len;i++){
//         ret = max(ret, dp[i]);
//     }   
//     return ret;
// }


int findLongestChain(vector<vector<int>>& pairs) {
    int cur = INT_MIN;
    int ret = 0;
    sort(pairs.begin(), pairs.end(), cmp);

    for(vector<int> item: pairs){
        if(item.front()>cur){
            cur = item.back();
            ret++;
        }
    }
    return ret;
}
int main(){
    vector<vector<int> > test = {{1,2}, {2,3}, {3,4}};
    cout<< findLongestChain(test) << endl;
}