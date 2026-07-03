class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue<pair<int,int>>pq;
    vector<int>ans;
    int maxi=nums[0];
    for(int i=0;i<k;i++){
      maxi= max(maxi,nums[i]);
      pq.push({nums[i],i});
    }
    ans.push_back(pq.top().first);
    for(int i=k;i<nums.size();i++){
      while(!pq.empty()){
      auto it = pq.top();
     //cout << it.first << endl;
       if(k==1) {pq.pop();break;}
      if(it.second >i-k && it.second<=i){
        break;
      }else{
        pq.pop();
      }
      }
             pq.push({nums[i],i});
      ans.push_back(pq.top().first);
    }
    return ans;
    }
};
