class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<pair<double, vector<int>>> pq;
        for(auto point : points){
            double dis = sqrt(pow(point[0],2)+pow(point[1],2)*1.0);
            pq.push({dis,point});
            if(pq.size()>k)pq.pop();
        }
         vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
        pq.pop();

        }
        return ans;
    }
};
