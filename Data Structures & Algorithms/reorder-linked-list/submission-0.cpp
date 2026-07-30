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
    void reorderList(ListNode* head) {
        stack<ListNode*>s;
        ListNode* slow=head;
        ListNode* fast=head ;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* mid = slow;
        slow=slow->next;
        mid->next=nullptr;
        while(slow){
            s.push(slow);
            slow=slow->next;
        }
          ListNode* curr=head;
          while(curr && s.size()){
             ListNode* temp = curr->next;
             curr->next= s.top();
             s.top()->next= temp;
             s.pop();
             curr= temp;
          }
        //   return head;
    }
};
