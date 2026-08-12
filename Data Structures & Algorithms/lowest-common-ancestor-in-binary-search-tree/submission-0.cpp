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
  
    bool path(TreeNode* root, TreeNode* p,   vector<TreeNode*>&v){
    if(!root)return false;
    if(root==p){v.push_back(root);return true;}
    bool found = path(root->left,p,v);
    if(found){
        v.push_back(root);
        return true;

    }
   found=  path(root->right,p,v);
if(found){
        v.push_back(root);
        return true;

    }
    return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       vector<TreeNode*>pv,qv;
       path(root,p,pv);
       path(root,q,qv);
       //cout << pv.size() << " "<< qv.size()<<endl;
       if(!pv.size() || !qv.size())return nullptr;
       int i=pv.size()-1,j=qv.size()-1;
       int prev=i;
       while(i>=0 && j>=0){
            if(pv[i] != qv[j]){
                break;
            }
             prev= i;
            i--;j--;
           
       }
       //return 0;
      return pv[prev];


    }
};
