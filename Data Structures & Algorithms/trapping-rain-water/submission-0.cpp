class Solution {
public:
    int trap(vector<int>& he) {
        int n = he.size();
        vector<int>suff(n,0);
        suff[n-1]=he[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=max(he[i],suff[i+1]);

        }
        int ans=0;
        int perff = 0;
        for(int i=0;i<n;i++){
            perff=max(perff,he[i]);
            int val =  min(perff,suff[i])-he[i];
            if(val>0){
                ans+=val;
            }
        }
        return ans;
    }
};
