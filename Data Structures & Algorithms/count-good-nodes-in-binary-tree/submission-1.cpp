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
    void findNodes(TreeNode* root, int &ans,int maxi){
        if(!root)return;
        if(maxi<=root->val)ans++;
        //cout << maxi << " "<< root->val << " " <<ans << endl;
        findNodes(root->left,ans,max(root->val,maxi));
        findNodes(root->right,ans,max(root->val,maxi));
    }
public:
    int goodNodes(TreeNode* root) {
       // if(!root)return 0;
        int maxi=INT_MIN;
        int ans=0;
        findNodes(root,ans,maxi);
        return ans;

    }
};
