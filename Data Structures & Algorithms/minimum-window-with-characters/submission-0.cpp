class Solution {
public:
    string minWindow(string s, string t) {
       int ans=INT_MAX,n=s.size(),r=0,low=-1,high=-1;
       if(t.size()>n)return "";
       unordered_map<char,int>s_freq;
       for(char ch : t)s_freq[ch]++;
       for(int i=0;i<=n-t.size();i++){
        if(s_freq.find(s[i])!=s_freq.end()){
            unordered_map<char,int>tempfreq;

            int index_s=i;
            int r=0;
            while(index_s<n && r<t.size()){
               
                 if(s_freq.find(s[index_s])!=s_freq.end()  &&(tempfreq[s[index_s]]<s_freq[s[index_s]])){
                    tempfreq[s[index_s]]++;
                    r++;
                 }
             if(r==t.size())break;
                index_s++;
            }

            // cout << s[index_s]  << " " << r << " "<< s.substr(i,index_s) << " " << (index_s-i)<<endl;
            //  for(auto it : tempfreq){
            //     cout << it.first << " "<< it.second<< " ;  ";
            //  }
            //  cout << endl;
            if(r==t.size()){
                if(ans > (index_s-i+1)){
                    high=index_s;
                    low=i;
                    ans= index_s-i+1;
                }
            }
        }
       }
       return high==-1?"":s.substr(low,ans);

    }
};
