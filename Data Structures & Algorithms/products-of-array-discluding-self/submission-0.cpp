class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
  
  int n = nums.size();
  vector<int> ans,suff(n+1,0);
  suff[n]=1;
  
  for(int i = n-1;i>=1;i--){
    suff[i]=suff[i+1]*nums[i];
  }
  long long  perff=1;
 // ans.push_back(suff[1]);
for(int i=0;i<n;i++){
ans.push_back(suff[i+1]*perff);
perff*=nums[i];
}
return ans;
    }
};
