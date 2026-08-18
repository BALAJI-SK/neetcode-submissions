class Solution {
    private: 
    void subsets(vector<int>&nums,int i,int target,int n ,vector<vector<int>>&ans,vector<int>&curr){
      
        if(target==0){
            ans.push_back(curr);
            return;
        }
          if(i==n)return;
           int j=i+1;
            for(;j<n;j++)if(nums[j]!=nums[i])break;
        if(target-nums[i]>=0){
            curr.push_back(nums[i]);
            subsets(nums,i+1,target-nums[i],n,ans,curr);
            curr.pop_back();
        }
         subsets(nums,j,target,n,ans,curr);
     
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>curr;
        int n= nums.size();
        unordered_set<int>sset;
          subsets(nums,0,target,n,ans,curr);
        // for(int i=0;i<n;i++){
        //     if(sset.find(nums[i])!=sset.end())continue;
        //     sset.insert(nums[i]);
        //     curr.push_back(nums[i]);
        //    //cout << nums[i]<<endl;
        //     subsets(nums,i,target-nums[i],n,ans,curr);
        //     curr.pop_back();
        // }
return ans;
    }
};
