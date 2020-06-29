#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

vector<int> sequentialDigits(int low, int high) {
    vector<int> all;
    for(int i=2;i<=9;i++){
        int initVal = 0;
        for(int j=1;j<=i;j++){
            initVal = initVal * 10 + j;
        }
        all.push_back(initVal);
        for(int k= 1;k<=9-i;k++){
            for(int m = 0;m<i;m++){
                initVal += pow(10, m);
            }
            all.push_back(initVal);
        }
    }

    vector<int> result;
    for(int i=0;i<all.size();i++){
        if(low <= all[i] && all[i] <= high){
            result.push_back(all[i]);
        }
    }
    return result;
}

int main(){
    int low = 100;
    int high = 3000000;
    vector<int> test = sequentialDigits(low, high);
    for(int item:test){
        cout<<item<<endl;
    }
}