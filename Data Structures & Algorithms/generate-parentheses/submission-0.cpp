class Solution {
    private :
    void backtrack(vector<string>&ans,string str,int n,int open, int close){
        if(open==n && close==n){
            ans.push_back(str);
            return;
        }
        if(open>close){
            backtrack(ans,str+')',n,open,close+1);
        }
        if(open<n){
        backtrack(ans,str+'(',n,open+1,close);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
         vector<string> ans;
        backtrack(ans,"",n,0,0);
        return ans;
    }
};
