#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int actualRob(TreeNode* root, map<TreeNode*, int>& record){
    if(root == nullptr){
        return 0;
    }

    if(record.count(root) == 1){
        return record[root];
    }

    TreeNode *lSon = root->left;
    TreeNode *rSon = root->right;

    //不偷root
    int val1 = (record.count(lSon) == 1?record[lSon]:actualRob(lSon, record)) + (record.count(rSon) == 1?record[rSon]:actualRob(rSon,record));
    //偷root
    int val2 = root->val;
    if(lSon != nullptr){
        TreeNode *ll = lSon->left;
        TreeNode *lr = lSon->right;
        val2 += (record.count(ll) == 1?record[ll]:actualRob(ll,record));
        val2 += (record.count(lr) == 1?record[lr]:actualRob(lr, record));
    }
    if(rSon != nullptr){
        TreeNode *rl = rSon->left;
        TreeNode *rr = rSon->right;
        val2 += (record.count(rl) == 1?record[rl]:actualRob(rl, record));
        val2 += (record.count(rr) == 1?record[rr]:actualRob(rr, record));
    }

    record.insert(make_pair(root, max(val1, val2)));
    return max(val1, val2);
}

int rob(TreeNode* root){
    map<TreeNode*, int> record;
    return actualRob(root, record);
}