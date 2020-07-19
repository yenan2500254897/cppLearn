#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
bool cmp(pair<string,int>& pre, pair<string,int>& next){
    return pre.second>next.second || (pre.second==next.second && pre.first<next.first);
}
vector<string> topKFrequent(vector<string>& words, int k) {
    
    map<string, int> frenquence;
    for(int i=0;i<words.size();i++){
        if(frenquence.count(words[i])==0){
            frenquence[words[i]] = 1;
        }else{
            frenquence[words[i]] += 1;
        }
    }
    vector<pair<string,int> > assistant;
    for(pair<string,int> p:frenquence){
        assistant.push_back(p);
    }
    sort(assistant.begin(), assistant.end(),cmp);

    int index =0;
    vector<string> result;
    while (index<k)
    {
        result.push_back(assistant[index].first);
        index++;
    }
    return result;

}

int main(){
    vector<string> vec = {"i", "love", "leetcode", "i", "love", "coding"};
    int k=2;
    vector<string> result = topKFrequent(vec, k);
}