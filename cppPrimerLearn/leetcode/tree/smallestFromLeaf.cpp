#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
string smallestFromLeaf(TreeNode* root) {
    queue<TreeNode*> nodesQueue;
    queue<string> record;
    vector<string> result;

    nodesQueue.push(root);
    record.push(string(1, 'a'+root->val));

    while (!nodesQueue.empty())
    {
        TreeNode* node = nodesQueue.front();
        string str = record.front();
        nodesQueue.pop();
        record.pop();

        if(node->left){
            nodesQueue.push(node->left);
            str.push_back('a'+node->left->val);
            record.push(str);
            str.pop_back();
        }

        if(node->right){
            nodesQueue.push(node->right);
            str.push_back('a'+node->right->val);
            record.push(str);
        }

        if(node->left == nullptr && node->right == nullptr){
            reverse(str.begin(), str.end());
            result.push_back(str);
        }
    }

    sort(result.begin(), result.end());
    return result.front();
}