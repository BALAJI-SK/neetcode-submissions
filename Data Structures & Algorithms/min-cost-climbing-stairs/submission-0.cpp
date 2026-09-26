class Solution {
    int f(auto& cost, int index,int n,auto&dp){
        if(index==n)return 0;
        if(index==n-1)return cost[n-1];
        if(index>n)return 1e9;
        if(dp[index]!=-1)return dp[index];
        return dp[index] = cost[index]+min(f(cost,index+1,n,dp),f(cost,index+2,n,dp));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);
        return min(f(cost,0,n,dp),f(cost,1,n,dp));
    }
};
