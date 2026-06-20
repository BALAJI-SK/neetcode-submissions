class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>uniq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            uniq.insert(nums[i]);
        }
        int ans=0,curr=0;
        for(int num : nums){
            if(uniq.find(num-1)==uniq.end()){
                curr=1;
                int ele=num;
                while(uniq.find(ele+1)!=uniq.end()){
                    curr++;
                    ele++;
                }
                ans=max(curr,ans);
            }
        }
        return ans;
    }
};
