#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

string generateFirst(vector<char> charVector, int n){
    sort(charVector.begin(), charVector.end());
    string firstStr = "";
    for(int i=0;i<n;i++){
        if(i == 0){
            firstStr.insert(firstStr.end(), charVector[0]);
        }else{
            char ch = (firstStr.back() == charVector[0]? charVector[1] : charVector[0]);
            firstStr.insert(firstStr.end(), ch);
        }
    }
    return firstStr;
}

string generateLast(vector<char> charVector, int n){
    sort(charVector.begin(), charVector.end());
    string lastStr = "";
    for(int i=0;i<n;i++){
        if(i == 0){
            lastStr.insert(lastStr.end(), charVector.back());
        }else{
            char ch = (lastStr.back() == charVector.back()? charVector[charVector.size()-2] : charVector.back());
            lastStr.insert(lastStr.end(), ch);
        }
    }
    return lastStr;
}

bool isHappy(string s){
    for(int i=1;i<s.length();i++){
        if(s[i] == s[i-1]){
            return false;
        }
    }
    return true;
}

string getHappyString(int n, int k) {
    vector<char> chars = {'a', 'b', 'c'};
    string first = generateFirst(chars, n);
    string last = generateLast(chars, n);

    if(k == 1){
        return first;
    }
    
    int currentStep = 1;
    string currentStr = first;

    while(currentStr <= last){
        // cout<<"currentStep: " << currentStep <<" currentStr: " << currentStr << endl;
        if(currentStr == last){
            return currentStep == k? currentStr:"";
        }

        if(currentStep == k){
            return currentStr;
        }

        bool flag = false;
        for(int i=n-1;i>=0;i--){
            char ch = currentStr[i];
            vector<char>::iterator iter = find(chars.begin(), chars.end(), ch);
            if(iter == chars.end()-1){
                flag = true;
                continue;
            }
            currentStr[i] = *(find(chars.begin(), chars.end(), ch) + 1);
            if(flag == true){
                for(int j=i+1;j<n;j++){
                    if((j-i)%2==1){
                        currentStr[j] = chars[0];
                    }else
                    {
                        currentStr[j] = chars[1];
                    }
                }
            }
            break;
            
        }
        if(isHappy(currentStr)){
            currentStep++;
        }
    }
    return "";
}

int getTotal(int n){
    return 3*(1<<(n-1));
}
string getHappyStringSec(int n, int k) {
    int total = getTotal(n);
    if(k>total){
        return "";
    }

    int len = 0;
    vector<char> result(n, ' ');
    for(int i=0;i<n;i++){
        if(i==0){
            int m = k*3/(total+1);
            result[0] = 'a'+ m;
            k = k-m*total/3;
        }else{
            char pre = result[i-1];
            if(k<=(1<<(n-i-1))){
                result[i] = (pre == 'a'? 'b':'a');
            }else{
                result[i] = (pre == 'c'? 'b':'c');
                k = k - (1<<(n-i-1));
            }
        }
        //cout<< "index "<< i <<": " << result[i] <<endl;
    }
    return string(result.begin(), result.end());
}


int main(){
    int n=3;
    int k=9;
    cout << getHappyStringSec(n, k) << endl;
}