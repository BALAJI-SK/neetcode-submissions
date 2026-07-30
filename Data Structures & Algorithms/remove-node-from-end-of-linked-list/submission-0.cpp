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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head,*slow = head;
        while(n){
            fast=fast->next;
            n--;
        }
        ListNode * prev = nullptr;
        while(fast){
            fast=fast->next;
            prev= slow;
            slow=slow->next;
        }
        if(prev==nullptr)return head->next;
        prev->next=slow->next;
        return head;

    }
};
