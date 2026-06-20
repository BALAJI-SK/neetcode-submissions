class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        int l =0,h=nums.size()-1;
        while(l<h){
            int val = nums[h]+nums[l];
            if(tar==val)return {l+1,h+1};
            if(tar<val)h--;
            else l++;
        }
        return {-1,-1};
    }
};
