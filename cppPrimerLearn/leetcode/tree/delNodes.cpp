#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    set<int> assitant;
    assitant.insert(to_delete.begin(), to_delete.end());

    queue<TreeNode*> visited;
    vector<TreeNode*> result;

    visited.push(root);
    while (!visited.empty())
    {
        TreeNode* cur = visited.front();
        // cout<<"cur: "<<cur->val<<endl;
        visited.pop();
        TreeNode* lNode = cur->left;
        TreeNode* rNode = cur->right;

        if(assitant.count(cur->val) == 0){
            if(result.empty()){
                result.push_back(cur);
            }
        }else
        {
            if(lNode && assitant.count(lNode->val) == 0){
                result.push_back(lNode);
            }

            if(rNode && assitant.count(rNode->val) == 0){
                result.push_back(rNode);
            }
        }
        if(lNode){
            visited.push(lNode);
        }
        if(rNode){
            visited.push(rNode);
        }
        
        if(lNode && assitant.count(lNode->val)==1){
            cur->left = nullptr;
        }

        if(rNode && assitant.count(rNode->val)==1){
            cur->right = nullptr;
        }
        
    }
    return result;

}

int main(){
    vector<int> test = {1,2,3,4,5,6,7};
    queue<TreeNode*> q;
    TreeNode *head = new TreeNode(test[0]);
    q.push(head);
    int index =1;
    while(index<test.size()){
        TreeNode *cur = q.front();
        q.pop();
        if(test[index] != NULL){
            TreeNode *l = new TreeNode(test[index]);
            cur->left = l;
            q.push(l);
        }
        index++;
        if(test[index] != NULL){
            TreeNode *r = new TreeNode(test[index]);
            cur->right = r;
            q.push(r);
        }
        index++;

    }
    vector<int> del = {3, 5};
    vector<TreeNode*> result = delNodes(head, del);
    return 0;
}
