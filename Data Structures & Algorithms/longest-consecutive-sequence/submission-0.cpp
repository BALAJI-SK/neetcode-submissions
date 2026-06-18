class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>sset;
        for(auto& it : nums){
            sset.insert(it);
        }
        int res=0;
        for(auto & num : sset){
            int streak=0,curr=num;
            while(sset.find(curr)!=sset.end()){
                streak++;
                curr++;
            }
            res =max(res,streak);
        }
        return res;
    }
};
