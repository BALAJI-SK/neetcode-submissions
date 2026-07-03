class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
      for(char ch : s){
        if(ch=='(' || ch=='{' || ch =='['){
          st.push(ch);
        }else {
          if(!st.empty() && ((ch==')' && st.top()=='(' ) || (ch==']' && st.top()=='[') || (ch=='}' && st.top()=='{'))){
           // cout << st.top()<< " ";
            st.pop();
          }else{
            return false;
          }
        }
        // cout << st.size()<< " ";
      }
      return st.empty();
    }
};
