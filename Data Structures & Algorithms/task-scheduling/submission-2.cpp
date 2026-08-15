
        class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
priority_queue<pair<int,char>>pq;
         vector<int>arr(26,0),ind(256,0);
       int size=0;
       char ch = 'A';
       for(char task:tasks){
        arr[task-ch]++;
       } 
       for(int val:arr){

        if(val)
        pq.push({val,ch});
        size+=val;
        ch++;
       }
       if(n==0)return size;
       int  ans=0;
       int loop=0;
        while(pq.size()){
            //ans++;
priority_queue<pair<int,char>>q; 
          int k=n+1;loop++;
          while(k && pq.size()){
            auto task = pq.top();
            pq.pop();
            k--;
            task.first--;
            if(loop>1){
            int diff =  n- (ans - ind[task.second]);
            //cout << diff << ":"<< ind[task.second]<<":"<<ans  << " ";
            if(diff>0){
                  
                ans+=diff;
            }
            }
            ans++;
            if(task.first)
            q.push({task.first,task.second});
            ind[task.second]=ans;
          }
          //cout << ans <<endl;
          while(q.size()){
             auto task = q.top();
            pq.push(task);
            q.pop();
          }
        }
        return ans;

    }
};

