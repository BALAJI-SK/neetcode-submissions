class Solution {
public:

    string encode(vector<string>& strs) {
string ans = "";
char esc= '\\';
char deil = '#';
for(string & str : strs ){
    for(char ch : str){
        if(ch==esc || ch == deil){
            ans.push_back(esc);
        }
        ans.push_back(ch);
    }
    ans.push_back(deil);
}
return ans;
    }

    vector<string> decode(string s) {
       // cout << s << endl;
        vector<string>ans;
        string curr="";
        int esc=0;
        for(char ch : s){
            if(ch=='#'){
                if(esc){
                     curr+=ch;
                     esc=0;
                }else{
                     ans.push_back(curr);
                    curr="";
                }
            } else if(ch=='\\'){
                if(esc==0)
                esc=1;
                else{
                  curr+=ch;
                  esc=0;
                }
            }else{
                curr+=ch;
            } 
        }
        // if(curr!="")
        // ans.push_back(curr);
        return ans;
    }
};
