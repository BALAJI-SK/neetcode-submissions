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
    void gets(TreeNode* root, vector<int>& value){
        if(!root)return ;
        gets(root->left,value);
        value.push_back(root->val);
        gets(root->right,value);
    }
    void gets(TreeNode* root, int k, int&count,int &ans ){
        if(!root)return ;
        gets(root->left,k,count,ans);
        count++;
        if(count==k){ans = root->val;return;}
        
        gets(root->right,k,count,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        // vector<int>value;
        int ans=0,count=0;
        gets(root,k,count,ans);
        return ans;
       // gets(root,value);
        //return value[k-1];
    }
};
