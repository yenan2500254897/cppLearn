#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findValue(vector<int>& A, int value){
    for(int i=0;i<A.size();i++){
        if(A[i]>value){
            A.erase(A.begin()+i);
            return A[i];
        }
    }
    for(int j=0;j<A.size();j++){
        int value = A.front();
        A.erase(A.begin());
        return value;
    }
    return -1;
}

vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    vector<int> result;
    vector<bool> visited(A.size(), false);

    sort(A.begin(), A.end());

    for(int i=0;i<B.size();i++){
        int value = findValue(A, B[i]);
        result.push_back(value);
    }
    return result;
}