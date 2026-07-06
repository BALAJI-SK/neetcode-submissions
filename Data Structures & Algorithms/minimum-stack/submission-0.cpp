class MinStack {
public:
vector<int>st;
int n;
int mini;
    MinStack() {
        n=0;
        mini=INT_MAX;
    }
    
    void push(int val) {
       n++;
       st.push_back(val); 
       mini=min(mini,val);
    }
    
    void pop() {
        if(n==-1)return;
      
        if(st[n-1]==mini){
            
            mini=INT_MAX;
              for(int i=0;i<n-1;i++){
                mini=min(mini,st[i]);
              }
        }
          n--;
       st.pop_back();

        
    }
    
    int top() {
        return st[n-1];
    }
    
    int getMin() {
        return mini;
    }
};
