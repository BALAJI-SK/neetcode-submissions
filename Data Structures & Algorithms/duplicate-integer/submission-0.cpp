class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>freq;
        for(auto i : nums){
            if(freq.find(i)!=freq.end()){
                return true;
            }else{
                freq.insert(i);
            }
        }
        return false;
    }
};