/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    private:
    void createo(TreeNode* root,int level,vector<int>&ans){
        if(!root)return;
        if(level==ans.size()){
            ans.push_back(root->val);

        }else{
            ans[level]=root->val;
        }

        createo(root->left,level+1,ans); 
        createo(root->right,level+1,ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        // createo(root,0,ans);
        if(!root)return ans;
        queue<TreeNode*>q;
        q.push(root);
        int size=1;
        while(!q.empty()){
            int val=0;
            size= q.size();
            while(size){
                TreeNode* curr =q.front();
                q.pop();
                val = curr->val;
                if(curr->left)
                q.push(curr->left);
                if(curr->right)
                q.push(curr->right);
                size--;
            }
            ans.push_back(val);
        }
        return ans;
    }
};
