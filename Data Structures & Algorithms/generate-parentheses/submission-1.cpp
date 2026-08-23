class Solution {
    private :
    void backtrack(vector<string>&ans,string& str,int n,int open, int close){
        if(open==n && close==n){
            ans.push_back(str);
            return;
        }
        if(open>close){
            str+=')';
            backtrack(ans,str,n,open,close+1);
            str.pop_back();
        }
        if(open<n){
            str+='(';
        backtrack(ans,str,n,open+1,close);
         str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
         vector<string> ans;
         string str="";
        backtrack(ans,str,n,0,0);
        return ans;
    }
};
