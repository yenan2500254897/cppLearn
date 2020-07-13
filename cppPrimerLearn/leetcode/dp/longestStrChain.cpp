#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

// 判断word2是否为word1的前缀
bool isContain(string& word1, string& word2){
    //两者长度相差必须为1
    if(word1.size() - word2.size() != 1){
        return false;
    }

    int diff = 0;

    for(int i=0;i<word2.size();i++){
        if(diff >= 2){
            return false;
        }

        if(word1[i+diff] != word2[i]){
            diff++;
            i--;
        }
    }
    return diff < 2? true:false;
}

bool cmp(string& str1, string& str2){
    return str1.length()<str2.length();
}

// 1048. 最长字符串链
int longestStrChain(vector<string>& words) {

    sort(words.begin(), words.end(), cmp);
    int len = words.size();
    // dp[i] 表示words[0]到words[i]范围的最长字符串链长度
    vector<int> dp(len, 1);

    for(int i=1;i<len;i++){
        for(int j=i-1;j>=0;j--){
            if(isContain(words[i], words[j])){
                //遇到第一个前缀，即返回
                // 原因：假设words[m] words[n]均为words[i]的前缀，且 m<n
                // 如果 dp[m]+1 > dp[n]+1, 则words[m]的长度大于words[n],则推出m>n,与上面假设矛盾
                dp[i] = dp[j]+1;
                break;
            }
        }
    }

    int ret = 0;
    for(int i=0;i<len;i++){
        ret = max(dp[i], ret);
    }
    return ret;

}

int main(){
    // vector<string> test = {"a","b","ba","bca","bda","bdca"};
    vector<string> test = {"ksqvsyq","ks","kss","czvh","zczpzvdhx","zczpzvh","zczpzvhx","zcpzvh","zczvh","gr","grukmj","ksqvsq","gruj","kssq","ksqsq","grukkmj","grukj","zczpzfvdhx","gru"};
    // cout<<isContain("ba", "b")<<endl;
    // cout<<isContain("ba", "a")<<endl;
    // cout<<isContain("b", "a")<<endl;
    // cout<<cmp("b", "a")<<endl;
    cout<<longestStrChain(test)<<endl;
}