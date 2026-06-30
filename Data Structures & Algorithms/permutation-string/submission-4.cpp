class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      unordered_map<int,int> count1,count2;
      for(int i=0;i<s1.size();i++){
        count1[s1[i]]++;
      } 
      int l=-1,curr=0;
      int n = s1.size();
      for(int r=0;r<s2.size();r++){
        if(count1.find(s2[r])==count1.end() ){
            curr=0;
            l=-1;
            count2.clear();
        }else if(l==-1){
           // cout << r << " "<< endl;
            count2[s2[r]]++;
            curr=1;
            l=r;
        }
        else if(count1[s2[r]]>=(count2[s2[r]]+1)){
            count2[s2[r]]++;
            curr++;
           
        }else {
            while(count1[s2[r]]<=count2[s2[r]]){
                curr--;
                count2[s2[l++]]--;
            }
            count2[s2[r]]++;curr++;
        }
         if(l!= -1 && curr==n){
           // cout << l << " "<< r << " "<< curr << " "<<endl;
                return true;
            }
      }
      return false;
    }
};
