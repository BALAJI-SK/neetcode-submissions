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
    int isbalance(TreeNode* root, bool& ans){
        if(!root)return 0;
        int left = isbalance(root->left,ans);
        int right = isbalance(root->right,ans);
        if(abs(left-right)>1)ans=false;
        return max(left,right)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        isbalance(root,ans);
        return ans;

    }
};
