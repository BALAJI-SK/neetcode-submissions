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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *curr= head;
        int carry=0;
        while(l1 && l2){
            int val = (l1->val+l2->val+carry);
            carry = val/10;
            val = val%10;
            ListNode* temp = new ListNode(val);
            l1=l1->next;
            l2=l2->next;
            curr->next = temp;
            curr = temp;
        }
        if(l1){
           while(carry && l1){
            int val = (l1->val+carry);
            carry = val/10;
            val = val%10;
            ListNode* temp = new ListNode(val);
            l1=l1->next;
            // l2 = l2->next;
               curr->next = temp;
            curr = temp;
           }
           if(l1){
            curr->next = l1;
           } 
        }
        if(l2){
           while(carry && l2){
            int val = (l2->val+carry);
            carry = val/10;
            val = val%10;
            ListNode* temp = new ListNode(val);
            l2=l2->next;
            curr->next = temp;
            curr = temp;
           }
           if(l2){
            curr->next = l2;
           } 
        }
        if(carry){
                   int val = (carry);
           ListNode* temp = new ListNode(val);
            curr->next = temp;
            curr = temp;
        }
        return head->next;
    }
};
