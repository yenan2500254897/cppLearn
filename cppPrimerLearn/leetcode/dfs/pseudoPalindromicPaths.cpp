#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

//判断能否构成回文字符串
bool isPalindromic(vector<int>& numberCount){
    int odd = 0;
    for(int i=1;i<10;i++){
        if(numberCount[i]%2==1){
            odd++;
        }
        if(odd>1){
            return false;
        }
    }
    return true;
}
//dfs解法
int pseudoPalindromicPaths (TreeNode* root) {
    //记录1到9的数量
    vector<int> numberCount(10, 0);
    //记录未访问到的节点
    stack<TreeNode*> dfs;
    //记录已经访问过的节点，换成map加速
    // vector<TreeNode*> visited;
    map<TreeNode*, int> visited;
    // 初始化
    int result  = 0;
    dfs.push(root);
    numberCount[root->val]++;
    while(!dfs.empty()){
        TreeNode* node = dfs.top();
        // 到达叶子节点
        if(node->left == nullptr && node->right == nullptr){
            // cout<<"arrive leaf: "<< node->val;
            if(isPalindromic(numberCount)){
                // cout<<" is palindrom";
                result++;
            }
            // cout<<endl;
            numberCount[node->val]--;
            dfs.pop();
            // visited.push_back(node);
            visited[node] = 1;
        }else{
            // 内部节点   
            //左节点未访问过
            if(node->left != nullptr && visited.count(node->left)==0){
                numberCount[node->left->val]++;
                dfs.push(node->left);
                // cout<<"go left: "<<node->left->val<<endl;
                continue;
            }
            // 右节点未访问过
            //查找find顺序查找，容易超时
            if(node->right != nullptr && visited[node->right]==0){
                numberCount[node->right->val]++;
                dfs.push(node->right);
                // cout<<"go right: "<<node->right->val<<endl;
                continue;
            }
            //左右节点均已经被访问过
            numberCount[node->val]--;
            dfs.pop();
            visited[node] = 1;
            // cout<<"pop middle node: "<<node->val<<endl;
        }
    }
    return result;
}