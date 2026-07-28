class Solution {
public:
    bool checkEating(vector<int>&piles , int h,int k){
        int count=0;
        int i=0,n=piles.size();
        int curr=0;
        while(i<n){
            // curr+=k;
            // if(curr>=piles[i]){
            //     i++;
            //     curr=0;
            //                 }
         

        count+=piles[i]/k + (piles[i]%k?1:0);
           i++;
           if(count>h)return false; 
        }
        return count<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int ans=r;
        while(l<=r){
            int mid = (r-l)/2+l;
            if(checkEating(piles,h,mid)){
                ans=min(ans,mid);
                r=mid-1;
            }else{
                l=mid+1;
            }
           //cout << mid << " "<< ans<<"\n";
        }
        return ans;
    }
};
