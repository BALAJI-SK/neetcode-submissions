
    class Solution {
    private:
   void subsets(vector<int>&nums,int i,int &n , vector<vector<int>> &ans, vector<int> & curr,int target){
    
    if(target==0){
        ans.push_back(curr);
        return;}
        if( i==n){
                return;
        }
        // for(auto c:curr)cout << c << " ";
        // cout << endl;
        

if(target-nums[i]>=0){
curr.push_back(nums[i]);
subsets(nums,i,n,ans,curr,target-nums[i]);
curr.pop_back();
}
subsets(nums,i+1,n,ans,curr,target);
    }


public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
           vector<vector<int>> ans;
           int n =nums.size();
           vector<int>curr;
           subsets(nums,0,n,ans,curr,target);
           return ans;
    }
};
