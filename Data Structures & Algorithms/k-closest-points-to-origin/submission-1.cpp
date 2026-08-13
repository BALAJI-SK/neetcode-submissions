class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<pair<double, int>> pq;
        for(int i=0;i<points.size();i++){
            auto& point = points[i];
            double dis = sqrt(pow(point[0],2)+pow(point[1],2)*1.0);
            pq.push({dis,i});
            if(pq.size()>k)pq.pop();
        }
         vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
        pq.pop();

        }
        return ans;
    }
};
