#include<iostream>
#include<vector>
#include<set>

using namespace std;

int maxLength(vector<string>& arr) {
    set<char> filter;
    vector<string> input;

    for(int i=0;i<arr.size();i++){
        filter.insert(arr[i].begin(), arr[i].end());
        if(filter.size() == arr[i].size()){
            input.push_back(arr[i]);
        }
        filter.clear();
    }

    vector<string> result;
    int ret = 0;
    for(int i=0;i<input.size();i++){
        int len = result.size();
        for(int j=0;j<len;j++){
            filter.insert(input[i].begin(), input[i].end());
            filter.insert(result[j].begin(), result[j].end());
            if(filter.size() == input[i].size()+result[j].size()){
                result.push_back(input[i]+result[j]);
                ret = max(ret, (int)filter.size());
            }
            filter.clear();
        }
        result.push_back(input[i]);
        ret = max(ret, (int)input[i].size());
    }
    return ret;

}

int main(){
    vector<string> test = {"un","iq","ue"};
    cout<<maxLength(test)<<endl;
}