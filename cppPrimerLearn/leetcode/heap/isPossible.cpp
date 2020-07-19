#include<iostream>
#include<vector>

using namespace std;

bool isPossible(vector<int>& nums) {
    vector<vector<int> > layer;
    int len = nums.size();
    // 初始化
    vector<int> init;
    init.push_back(nums[0]);
    layer.push_back(init);
    // 循环
    for(int i=1;i<len;i++){
        int j=layer.size()-1;
        for(;j>=0;j--){
            if(nums[i] == layer[j].back()+1){
                layer[j].push_back(nums[i]);
                break;
            }
        }
        if(j==-1){
            vector<int> newLayer;
            newLayer.push_back(nums[i]);
            layer.push_back(newLayer);
        }
    }

    for(int k=0;k<layer.size();k++){
        if(layer[k].size()<3){
            return false;
        }
    }
    return true;
}