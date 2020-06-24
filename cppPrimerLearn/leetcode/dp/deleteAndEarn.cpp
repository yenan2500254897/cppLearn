#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// bool finish(vector<int>& nums){
//     for(vector<int>::iterator iter = nums.begin();iter!=nums.end();iter++){
//         if(*iter != 0){
//             return false;
//         }
//     }
//     return true;
// }

// int deleteAndEarn(vector<int>& nums) {
//     if(nums.empty()){
//         return 0;
//     }

//     if(nums.size() == 1){
//         return nums[0];
//     }
    
//     sort(nums.begin(), nums.end());
//     vector<vector<int> > position(10002, vector<int>(2, -1));

//     //iter遍历nums用
//     vector<int>::iterator iter ;
//     //index记录使当前nums损失最小的数
//     vector<int>::iterator index;
//     //记录当前nums的最小损失
//     int loss = INT32_MAX;
//     //记录到目前为止获得的点数
//     int result = 0;

//     //初始化position
//     for(iter = nums.begin();iter!=nums.end();iter++){
//         int value = *iter;
//         if(position[value][0] == -1){
//             position[value][0] = iter - nums.begin();
//             position[value][1] = iter - nums.begin();
//         }else{
//             position[value][1] = iter - nums.begin();
//         }
//     }

//     while(!finish(nums)){
//         loss = INT32_MIN;
//         for(iter = nums.begin();iter!=nums.end();iter++){
//             int currentValue = *iter;
//             if(currentValue == 0){
//                 continue;
//             }

//             int left = currentValue - 1;
//             int right = currentValue + 1;

//             int currentLoss = currentValue;
//             if(position[left][0] >= 0){
//                 currentLoss -= (position[left][1] - position[left][0] + 1) * left;
//             }
//             if(position[right][0] >= 0){
//                 currentLoss -= (position[right][1] - position[right][0] + 1) * right;
//             }

//             if(currentLoss>loss){
//                 loss = currentLoss;
//                 index = iter;
//             }
            
//         }

//         result += *index;
//         if(position[*index -1][0] >= 0){
//             for(vector<int>::iterator leftIter = nums.begin()+position[*index-1][0];
//             leftIter<=nums.begin()+position[*index-1][1];leftIter++){
//                 *leftIter = 0;
//             }
//             position[*index -1][0] = -1;
//             position[*index -1][1] = -1;
//         }

//         if(position[*index +1][0] >= 0){
//             for(vector<int>::iterator rightIter = nums.begin()+position[*index+1][0];
//             rightIter<=nums.begin()+position[*index+1][1];rightIter++){
//                 *rightIter = 0;
//             }
//             position[*index + 1][0] = -1;
//             position[*index + 1][1] = -1;
//         }
//         *index = 0;


//     }
//     return result;
// }

int deleteAndEarn(vector<int>& nums) {
    if(nums.empty()){
        return 0;
    }

    sort(nums.begin(), nums.end());

    int len = nums.back();

    vector<int> counts(len+1, 0);
    for(int i=0;i<nums.size();i++){
        counts[nums[i]]++;
    }

    vector<int> dp(len+1, 0);
    for(int i=1;i<=len;i++){
        dp[i] = max(i*counts[i] + (i-2>0?dp[i-2]:dp[0]), dp[i-1]);
    }
    return dp[len];
}

int main(){
    int nums[] = {2, 2, 3, 3, 3, 4};
    vector<int> test(nums, nums + sizeof(nums)/sizeof(nums[0]));
    cout<<deleteAndEarn(test)<<endl;
}