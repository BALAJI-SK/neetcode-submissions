class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>unq;
        int l=0,ans=0;
        for(int r=0;r<s.size();r++){
            while(unq.find(s[r])!=unq.end() ){
                unq.erase(s[l++]);
            }
            ans= max(ans,r-l+1);
            unq.insert(s[r]);
            //cout << ans << endl;
        }
        return ans;

    }
};
