class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n= temps.size();
        vector<int>ans(n,0);
        stack<int>st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
         
     while(!st.empty()){
            //auto warm = st.top();
            if(temps[st.top()]<=temps[i]){
                st.pop();
            }else{
                ans[i]=st.top()-i;
                break;
            }

     }
     st.push(i);
         
        }
        return ans;

    }
};
