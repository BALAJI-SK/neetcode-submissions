class Solution {
    private:
   void subsets(vector<int>&nums,int i,int &n , vector<vector<int>> &ans, vector<int> & curr){
        if(i==n){
                ans.push_back(curr);
                return;
        }
        
subsets(nums,i+1,n,ans,curr);
curr.push_back(nums[i]);
subsets(nums,i+1,n,ans,curr);
curr.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
           vector<vector<int>> ans;
           int n =nums.size();
           vector<int>curr;
           subsets(nums,0,n,ans,curr);
           return ans;
    }
};
