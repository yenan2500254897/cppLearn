#include<iostream>
using namespace std;

string pushDominoes(string dominoes) {
    dominoes.insert(dominoes.begin(),'L');
    dominoes.insert(dominoes.end(), 'R');
    int len = dominoes.size();
    
    string result = "";

    for(int i=1;i<len-1;i++){
        // cout<<"i= "<<i<<" ch= " <<dominoes[i]<<endl;
        if(dominoes[i]!='.'){
            // cout<<"case0: direct insert"<<endl;
            result.insert(result.end(), dominoes[i]);
        }else{
            int left = i;
            int right = i;
            while(i+1<len-1 && dominoes[i+1] == '.'){
                i++;
                right=i;
            }
            // cout<<"left=" << left<<" right="<<right<< " is ."<<endl;
            int interval = right-left+1;
            if(dominoes[left-1]==dominoes[right+1]){
                // cout<<"case 3: insert"<<interval<<"个"<<dominoes[left-1]<<endl;
                result.insert(result.end(), interval, dominoes[left-1]);
            }else if(dominoes[left-1] == 'L' && dominoes[right+1] == 'R'){
                // cout<<"case 4: insert"<<interval<<"个."<<endl;
                result.insert(result.end(), interval, '.');
            }else{
                // cout<<"case 5: insert "<< interval/2 <<"个R ";
                result.insert(result.end(), interval/2, 'R');
                if(interval%2){
                    // cout<<" insert "<< 1 <<" 个.";
                    result.insert(result.end(), '.');
                }
                // cout<<"insert "<< interval/2 <<"个L ";
                result.insert(result.end(), interval/2, 'L');
            }

        }
    }
    return result;
}

int main(){
    string s= ".L.R...LR..L..";
    cout<<pushDominoes(s)<<endl;
}
