#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int numComponents(ListNode* head, vector<int>& G) {
    map<int, int> record;
    for(int i=0;i<G.size();i++){
        int val = G[i];
        record[val] = val;
    }

    ListNode* node = head;
    int result = 0;
    while (node != nullptr)
    {
        if(record.count(node->val)>0){
            while(node!=nullptr && record.count(node->val)>0){
                node = node->next;
            }
            result++;
        }else
        {
            node=node->next;
        }
        
    }
    return result;
    
}