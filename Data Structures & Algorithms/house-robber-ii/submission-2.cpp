class Solution {
    int robi(int index,int n,auto& nums,auto& dp,int flag){
        if(index>=n)return 0;
    if(dp[index][flag]!=-1)return dp[index][flag];
        return dp[index][flag]=max(nums[index]+robi(index+2,n,nums,dp,flag),robi(index+1,n,nums,dp,flag));
    }
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1)return nums[0];
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return max(robi(0,n-1,nums,dp,0),robi(1,n,nums,dp,1));
    }
};
