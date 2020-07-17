#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// int findNextValue(vector<int>& record, int index, int val){
//     int i=index+1;
//     for(;i<record.size();i++){
//         if(record[i]>val){
//             break;
//         }
//     }
//     return i<record.size()?record[i]:-1;
// }

// vector<int> nextLargerNodes(ListNode* head) {
//     ListNode* node = head;
//     int len =0;
//     vector<int> record(10001);
//     while (node != nullptr)
//     {
//         record[len] = node->val;
//         len++;
//         node = node->next;
//     }
    
//     vector<int> result(len, 0);
//     for(int i=0;i<len;i++){
//         int val = findNextValue(record, i, record[i]);
//         if(val!=-1){
//             result[i] = val;
//         }
//     }
//     return result;
// }

vector<int> nextLargerNodes(ListNode* head) {

    vector<int> v;
    ListNode* cur = head;
    while (cur)
    {
        ListNode* next = cur->next;
        while (next)
        {
            if (next->val > cur->val)
            {
                v.push_back(next->val);
                break;
            }
            next = next->next;
        }
        
        if(next == nullptr)
            v.push_back(0);

        cur = cur->next;
    }

    return v;
}
