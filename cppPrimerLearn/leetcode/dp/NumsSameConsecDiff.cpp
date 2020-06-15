#include<iostream>
#include<vector>
#include<set>

using namespace std;
vector<int> findAllNumber(vector<int> , int );
vector<int> numsSameConsecDiff(int N, int K) {
    vector<int> result;
    

    for(int i=0;i<=9;i++){
        if(i==0 && N != 1){
            continue;
        }
        result.push_back(i);
    }

    int circle = 1;
    while(circle<N){
        result = findAllNumber(result, K);
        if(result.empty()){
            break;
        }
        circle++;
    }
    return result;
}

vector<int> findAllNumber(vector<int> pre, int diff){
    set<int> next;

    while(!pre.empty()){
        int currentValue = pre.back();
        pre.pop_back();

        int lastPosValue = currentValue % 10;
        if(lastPosValue + diff < 10){
            int addValue = currentValue*10 + (lastPosValue + diff);
            next.insert(addValue);
        }

        if(lastPosValue - diff>=0){
            int subValue = currentValue*10 + (lastPosValue - diff);
            next.insert(subValue);
        }

    }
    vector<int> result(next.cbegin(), next.cend());
    return result;
}

int main(){

    vector<int> test = numsSameConsecDiff(2,0);
    vector<int>::iterator iter = test.begin();
    while(iter != test.end()){
        cout<<" "<< *iter <<" ";
        iter++;
    }
    cout<<endl;


}