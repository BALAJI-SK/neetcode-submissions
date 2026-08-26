class Solution {
public:
vector<string> res;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
           if (digits.empty()) return res;
           res.push_back("");
       for (char digit : digits) {
            vector<string> tmp;
            for (string &curStr : res) {
                for (char c : digitToChar[digit - '0']) {
                    tmp.push_back(curStr + c);
                }
            }
           // cout << tmp.size()<<endl;
            res = tmp;
        }
        return res;
    }
    void backtrack(int i,string curStr,string &digits){
         if (curStr.size() == digits.size()) {
            res.push_back(curStr);
            return;
        }
        string chars = digitToChar[digits[i] - '0'];
        for (char c : chars) {
            backtrack(i + 1, curStr + c, digits);
        }
    }
};
