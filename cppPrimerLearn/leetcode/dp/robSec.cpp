#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findSolution(vector<int>& nums) {
    if(nums.empty()){
        return 0;
    }

    int len = nums.size();
    vector<int> dp(len + 1, 0);

    for(int i=1;i<=len;i++){
        dp[i] = max(dp[i-1],  nums[i-1] + dp[max(i-2, 0)]);
    }
    return dp[len];
}

int rob(vector<int>& nums){
    if(nums.empty()){
        return 0;
    }
    if(nums.size() == 1){
        return nums[0];
    }
    vector<int> vec1(nums.begin(), nums.end()-1);
    vector<int> vec2(nums.begin()+1, nums.end());
    int val1 = findSolution(vec1);
    int val2 = findSolution(vec2);
    return max(val1, val2);
}
int main(){
    // int arr[] = {1,2,3,1};
    // int arr[] = {1,1,1,2};
    int arr[] = {1,1,3,6,7,10,7,1,8,5,9,1,4,4,3};
    vector<int> vec(arr, arr+sizeof(arr)/sizeof(int));
    cout << rob(vec) << endl;
}