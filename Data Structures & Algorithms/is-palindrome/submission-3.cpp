class Solution {
public:
    bool isalpah(char ch){
        cout << ch << endl;
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9') ){
            return true;
        }
  
        return false;
    }
    int  isnumeric(char ch){
        if (ch>='0' && ch<='9'){
            return 1;
        }
       
        return 2;
    }
    bool isPalindrome(string s) {
        int l=0,h=s.size()-1;int n =h+1;

        while(l<h){
            while(l<h && !isalpah(s[l]))l++;
    
            while(l<h && !isalpah(s[h]))h--;

            int ch1 = isnumeric(s[l]);
            int ch2 = isnumeric(s[h]);
            if(ch1!=ch2)return false;
         if (tolower(s[l]) != tolower(s[h])) return false;
            l++;h--;

        }
        return true;
    }
};
