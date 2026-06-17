class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int,int>umap;
        int l=0, h = nums.size();
        while(l<h){
            
           if(umap.find(target-nums[l])!=umap.end()){
            return {umap[target-nums[l]],l};
           }
           umap[nums[l]]=l;
           l++;
            
        }
        return {-1,-1};
    }
};
