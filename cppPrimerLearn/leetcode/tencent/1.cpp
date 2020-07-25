#include<iostream>
#include<vector>

using namespace std;

void constructLeft(vector<int>& input, vector<int>& left){
    for(int i=1;i<input.size();i++){
        for(int j=i-1;j>=0;j--){
            if(input[i]<input[j]){
                left[i] = left[j]+1;
                break;
            }
        }
    }
    return;
}

void constructRight(vector<int>& input, vector<int>& right){
    for(int i=input.size()-2;i>=0;i--){
        for(int j=i+1;j<input.size();j++){
            if(input[i]<input[j]){
                right[i] = right[j]+1;
                break;
            }
        }
    }
    return;
}

int main(){
    int N;
    cin>>N;
    vector<int> input(N, 0);
    vector<int> left(N, 0);
    vector<int> right(N, 0);

    for(int i=0;i<N;i++){
        int value;
        cin>>value;
        input[i] = value;
    }
    constructLeft(input, left);
    constructRight(input, right);

    for(int i=0;i<N;i++){
        int result = 1;
        if(i-1>=0){
            result += left[i-1]+1;

        }
        if(i+1<N){
            result += right[i+1]+1;
        }
        cout<<result<<" ";
    }
}