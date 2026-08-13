class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int stone : stones)pq.push(stone);
        while(pq.size()>=2){
            int one = pq.top();pq.pop();
            int two = pq.top();pq.pop();
            int diff= abs(one-two);
            if(diff){
                pq.push(diff);
            }
        }
        return pq.empty()?0:pq.top();
    }
};
