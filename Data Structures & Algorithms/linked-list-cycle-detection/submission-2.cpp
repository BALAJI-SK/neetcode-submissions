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
    bool hasCycle(ListNode* head) {
        ListNode*  fast = head;
       ListNode*  slow = head;
       if(!head)return false;
       do{
        if(fast ->next ){
            fast = fast->next->next;
        }else return false;
        slow = slow->next;
       }while(fast &&  fast != slow );
        return fast ? true: false;
    }
};
