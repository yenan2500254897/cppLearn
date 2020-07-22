#include<iostream>
#include<set>
#include<string>
#include<unordered_set>
using namespace std;

// bool hasAllCodes(string s, int k) {
//     int limit = (1<<k);
//     stringstream ss;
//     for(int i=0;i<limit;i++){
//         bool flag = false;
//         for(int j=0;j<=s.size()-k;j++){
//             string str(s.begin()+j, s.begin()+j+k);
//             int value = stoi(str, 0, 2);
//             if(value == i){
//                 flag = true;
//                 break;
//             }
//         }
//         if(!flag){
//             return false;
//         }
//     }
//     return true;
// }


bool hasAllCodes(string s, int k) {
    if(k>=s.size()){

        return false;
    }
    
    unordered_set<string> record;
    for(int i=0;i<=s.size()-k;i++){
        
        record.insert(s.substr(i, k));
    }

    int limit = (1<<k);
    
    return record.size() == limit;
}

int main(){
    // string s="00110110";
    // string s="0110";
    string s = "0000000001011100";
    int k=4;
    cout<<hasAllCodes(s, k)<<endl;
}