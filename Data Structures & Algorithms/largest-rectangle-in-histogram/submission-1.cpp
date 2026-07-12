class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int,int>>st;
        int ans=0;
        for(int i=0;i<n;i++){
           
            ans=max(ans,heights[i]);
             if(st.empty())st.push({i,heights[i]});
             else{
                int start=i;
                while(!st.empty() && st.top().second>heights[i]){
                    start=st.top().first;
                    
                    ans=max(ans,st.top().second*(i-start));
                    st.pop();
                }
                st.push({start,heights[i]});
cout << ans << endl;
             }

                    }
                    while(st.size()){
                        ans= max(ans,st.top().second*(n-st.top().first));
                        st.pop();
                    }
                    return ans;

    }
};
