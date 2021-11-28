/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode nuevonodo(0);
    ListNode *fin = &nuevonodo;

    while(l1 && l2){
        if(l1->val < l2->val) {
            fin->next = l1;
            l1 = l1->next;
            
        } else {
            fin->next = l2;
            l2 = l2->next;
        }
        
        fin = fin->next;
    }

    if (l1){
        fin->next = l1;
    } else {
        fin->next = l2;
    }
        return nuevonodo.next;
    }
};