class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int t) {
          vector<int> ans;
          unordered_map<int,int>freq;
          for(auto & i : nums)freq[i]++;
         vector<vector<int>>m(nums.size()+2,vector<int>());
         for(auto& it : freq){
            m[it.second].push_back(it.first);
            //cout << it.first << endl;
         }
         int k=0;
         for(int i=nums.size();i>=0;i--){
            for(auto & it : m[i]){
                ans.push_back(it);
                k++;
               // cout << k << endl;
                if(t==k)return ans;
            }
         }

          return ans;
    }
};
