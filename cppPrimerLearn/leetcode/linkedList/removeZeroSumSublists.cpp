#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode* node = head;
    ListNode* pre = nullptr;
    while(node!=nullptr){
        ListNode* temp = node;
        int total = 0;
        while(temp!=nullptr){
            total+=temp->val;
            if(total == 0){
                if(pre == nullptr){
                    head = temp->next;
                }else
                {
                    pre->next = temp->next;
                }
                pre = nullptr;
                node = head;
                break;
            }else
            {
                temp = temp->next;
            }
        }
        if(temp == nullptr){
            pre = node;
            node=node->next;
            
        }
    }
    return head;
}