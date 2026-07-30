/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newhead=nullptr;
        Node* curr= head;
        unordered_map<Node*,Node*>umap;
        Node* prev= nullptr;
            while(curr){
                Node* newNode = new Node(curr->val);
                if(newhead==nullptr){
                    newhead= newNode;
                }else{
                    prev->next= newNode;
                }
                prev= newNode;
                umap[curr]=newNode;
                curr=curr->next;
            }
            prev=newhead;
            curr= head;
            while(prev){
                prev->random=umap[curr->random];
                prev= prev->next;
                curr=curr->next;
            }
            return newhead;

    }
};
