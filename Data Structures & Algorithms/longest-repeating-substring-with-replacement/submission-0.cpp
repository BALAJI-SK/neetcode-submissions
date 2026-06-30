class Solution {
public:
    int characterReplacement(string s, int k) {
   
        unordered_set<int>uniq(s.begin(),s.end());
        int ans=0;
        for(char ch : uniq){
            int l=0,count=0;
            for(int r=0;r<s.size();r++){
                if(s[r]==ch){
                    count++;
                }else{
                    while((r-l+1)-count>k){
                          if(s[l]==ch)count--;
                        l++;
                      
                    }
                }
                ans=max( (r-l+1),ans);
            }
        }
        return ans;
    }
};

  
