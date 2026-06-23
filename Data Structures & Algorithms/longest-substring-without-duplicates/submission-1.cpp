class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>umap;
        int curr=0,ans=0;
        int l=0;
        for(int i=0;i<s.size();i++){
            if(umap.find(s[i])!=umap.end()){
                int j=l;
                 l=umap[s[i]]+1;
                while(j<l){
                    umap.erase(s[j++]);
                }
                   
                    curr= i-l;
                    umap[s[i]]=i;
            }else{
                umap[s[i]]=i;
            }
            //cout << l << " " << curr << endl;
            ans= max(ans,++curr);
        }
        return ans;
    }
};
