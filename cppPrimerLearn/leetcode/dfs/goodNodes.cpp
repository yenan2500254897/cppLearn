#include<iostream>
#include<stack>
#include<set>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int goodNodes(TreeNode* root) {
    stack<TreeNode*> nodes;
    stack<int> assistant;
    set<TreeNode*> visited;

    nodes.push(root);
    assistant.push(root->val);
    int result = 1;
    while(!nodes.empty()){
        TreeNode* cur = nodes.top();
        if(cur->left == nullptr && cur->right == nullptr){
            visited.insert(cur);
            nodes.pop();
            assistant.pop();
            cout<<"arrive leaf node:"<<cur->val<<endl;
        }else
        {
            if(cur->left && visited.count(cur->left) ==0){
                nodes.push(cur->left);
                assistant.push(max(cur->left->val, assistant.top()));
                if(assistant.top() == cur->left->val){
                    result++;
                }
                cout<<"add left node:"<<cur->left->val<<endl;
                continue;
            }

            if(cur->right && visited.count(cur->right) ==0){
                nodes.push(cur->right);
                assistant.push(max(cur->right->val, assistant.top()));
                if(assistant.top() == cur->right->val){
                    result++;
                }
                cout<<"add right node:"<<cur->right->val<<endl;
                continue;
            }

            visited.insert(cur);
            nodes.pop();
            assistant.pop();
            cout<<"pop inner node:"<<cur->val<<endl;

        }
        
    }
    return result;
}