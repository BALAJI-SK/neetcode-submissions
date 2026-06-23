class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans=0,n=p.size();
        vector<int>suff(n+1,0);
        for(int i=n-1;i>=0;i--){
            suff[i]=max(p[i],suff[i+1]);
        }
        for(int i=0;i<n;i++){
            if(p[i]<suff[i]){
                ans= max(suff[i]-p[i],ans);
            }
        }
    return ans;}
};
