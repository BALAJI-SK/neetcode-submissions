class Solution {
public:
    bool issign(string &s){
        if(s=="+" || s=="-" || s=="*" || s=="/"){
            return true;
        }
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto token: tokens ){
            if(issign(token)){
                  int val1 = st.top();
                        st.pop();
                        int val2 = st.top();
                        st.pop();
                switch(token[0]){
                    case '+':
                        val1+=val2;
                        break;
                    case '-':
                    val1=val2-val1;
                    break;
                    case '/':
                    val1=val2/val1;
                    break;
                    case '*':
                    val1*=val2;
                    break;
                }
                st.push(val1);
            }else{
                st.push(stoll(token));
            }
            cout << token << " "<< st.top()<< endl;
        }
        return st.top();
    }
};
