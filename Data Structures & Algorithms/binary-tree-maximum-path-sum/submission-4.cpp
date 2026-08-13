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
    int dfs(TreeNode* root,int & ans){
        if(!root)return INT_MIN;
        // if(!root->left && !root->right){return root->val;}
        int left = dfs(root->left,ans);
        int right = dfs(root->right,ans);
        int sum = (left<0?0:left) + (right<0?0:right);
        ans= max(ans,root->val+sum);
        
        return (max(left,right)<0?0:max(left,right))+root->val;

    }
public:
    int maxPathSum(TreeNode* root) {
        int ans =INT_MIN;
        dfs(root,ans);
        return ans==INT_MIN?0:ans;
        
    }
};
