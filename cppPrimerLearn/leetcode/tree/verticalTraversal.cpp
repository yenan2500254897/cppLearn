#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct TreeNode {
 int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

static bool cmp(vector<int> pre, vector<int> next){
    return pre[0]<next[0] || (pre[0] == next[0] && pre[1]>next[1]) || (pre[0] == next[0] && pre[1]==next[1] && pre[2]<next[2]);
}
 vector<vector<int>> verticalTraversal(TreeNode* root) {
     queue<TreeNode*> nodesQueue;
     queue<vector<int>> assitant;
     vector<vector<int> > coordinates;

     nodesQueue.push(root);
     vector<int> init;
     init.push_back(0);
     init.push_back(0);
     assitant.push(init);
     init.push_back(root->val);
     coordinates.push_back(init);

     while(!nodesQueue.empty()){
         TreeNode* cur = nodesQueue.front();
         vector<int> coor = assitant.front();
         nodesQueue.pop();
         assitant.pop();

         if(cur->left){
             nodesQueue.push(cur->left);
             vector<int> lVec;
             lVec.push_back(coor.front()-1);
             lVec.push_back(coor.back()-1);
             assitant.push(lVec);
             lVec.push_back(cur->left->val);
             coordinates.push_back(lVec);
            //  cout<<"add x:"<<coor.front()-1<<"  y:"<<coor.back()-1<<"  val:"<<cur->left->val<<endl;
         }

         if(cur->right){
             nodesQueue.push(cur->right);
             vector<int> rVec;
             rVec.push_back(coor.front()+1);
             rVec.push_back(coor.back()-1);
             assitant.push(rVec);
             rVec.push_back(cur->right->val);
             coordinates.push_back(rVec);
            //  cout<<"add x:"<<coor.front()+1<<"  y:"<<coor.back()-1<<"  val:"<<cur->right->val<<endl;
         }
     } 
     sort(coordinates.begin(), coordinates.end(),cmp);

     map<int,vector<int>> m;
     for(int i=0;i<coordinates.size();i++){
         m[coordinates[i][0]].push_back(coordinates[i][2]);
     }

     vector<vector<int> > result;
     for(map<int,vector<int>>::iterator iter=m.begin();iter!=m.end();iter++){
         result.push_back(iter->second);
     }  
     return result;   
}