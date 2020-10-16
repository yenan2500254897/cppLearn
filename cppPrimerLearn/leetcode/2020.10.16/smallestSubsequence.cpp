#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
/*
1081. 不同字符的最小子序列
返回字符串 text 中按字典序排列最小的子序列，该子序列包含 text 中所有不同字符一次。
 
*/
using namespace std;

string smallestSubsequence(string s) {
    int len = s.size();
    vector<char> result;

    for(int i=0;i<len;i++){
        char cur = s[i];
        if(find(result.begin(), result.end(), cur) != result.end()){
            continue;
        }
        while(!result.empty() && result.back()>cur && find(s.begin()+i+1, s.end(), result.back())!=s.end()){
            result.pop_back();
        }
        result.push_back(cur);
    }
    string resultStr = "";
    for(auto item:result){
        resultStr.push_back(item);
    }
    return resultStr;
}
int main(){
    string test = "cdadabcc";
    cout << smallestSubsequence(test) << endl;
    return 0;
}