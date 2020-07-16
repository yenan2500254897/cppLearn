#include<iostream>
#include<sstream>
#include<deque>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int findNumber(string S, int& index){
    int i=index;
    for(;i<S.size();i++){
        if(S[i]=='-'){
            break;
        }
    }
    string str(S.begin()+index, S.begin()+i);
    int number;
    stringstream ss;
    ss<<str;
    ss>>number;
    
    index = i;
    return number;
}

int findSymbol(string S, int& index){
    int i=index;
    for(;i<S.size();i++){
        if(i+1>=S.size() || S[i+1]!='-'){
            break;
        }
    }
    int len = i-index+1;
    index = i+1;
    return len;
}


// TreeNode* recoverFromPreorder(string S) {
//     deque<TreeNode*> nodesQueue;
//     deque<int> assistant;
    
//     int index = 0;
//     int rootVal = findNumber(S,index);
//     TreeNode* root = new TreeNode(rootVal);
//     nodesQueue.push_back(root);
//     assistant.push_back(0);

//     while(!nodesQueue.empty() && index<S.size()){
//         int symbolLen = findSymbol(S, index);
//         int val = findNumber(S, index);
//         TreeNode* node = new TreeNode(val);
//         if(symbolLen>assistant.back()){
//             nodesQueue.back()->left = node;
//             nodesQueue.push_back(node);
//             assistant.push_back(symbolLen);
//         }else{
//             while(assistant.back()>=symbolLen){
//                 nodesQueue.pop_back();
//                 assistant.pop_back();
//             }

//             nodesQueue.back()->right=node;
//             nodesQueue.push_back(node);
//             assistant.push_back(symbolLen);
//         }
//     }
//     return root;
// }


TreeNode* recoverFromPreorder(string S) {
    if(S.empty()){
        return nullptr;
    }
    int index = 0;
    int rootVal = findNumber(S,index);
    TreeNode* root = new TreeNode(rootVal);
    if(index==S.size()){
        return root;
    }

    int symbolLen = findSymbol(S,index);
    int pre = index;
    findNumber(S, index);
    while(index<S.size() && symbolLen!=findSymbol(S,index) ){
        findNumber(S,index);
    }

    string leftStr(S.begin()+pre, S.begin()+index);
    string rightStr(S.begin()+index, S.end());
    // cout<<"left string: "<<leftStr<<"  right string: "<< rightStr<<endl;
    root->left = recoverFromPreorder(leftStr);
    root->right = recoverFromPreorder(rightStr);
   
    return root;
}

int main(){
    // string s="1-2--3--4-5--6--7";
    string s = "1-2--3---4-5--6---7";
    TreeNode *root = recoverFromPreorder(s);
}