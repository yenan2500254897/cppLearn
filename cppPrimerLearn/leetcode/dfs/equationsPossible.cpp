#include<vector>

using namespace std;
int father[26];
int findFather(int x){
    return x==father[x]?x:findFather(father[x]);
}
void merge(int x, int y){
    father[findFather(y)] = findFather(x);
}

bool equationsPossible(vector<string>& equations) {

    
    for(int i=0;i<26;i++){
        father[i] = i;
    }

    for(int j=0;j<equations.size();j++){
        char ch =equations[j][1];
        if(ch == '='){
            merge(equations[j][0]-'a', equations[j][3]-'a');
        }
    }
    for(int k=0;k<equations.size();k++){
        char ch =equations[j][1];
        if(ch == '!'){
            if(findFather(equations[k][0]-'a') == findFather(equations[k][3]-'a')){
                return false;
            }
        }
    }
    return true;
}