class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int squares[9] = {0};
        int n=board.size();
        for(int r=0;r<n;r++){
            
            for(int c=0;c<n;c++){
                char val = board[r][c];
                if(val=='.')continue;
                int squareKey= (r/3)*3+(c/3);
                if(rows[r] & (1<< val)|| cols[c]& (1<< val)|| squares[squareKey]& (1<< val)){
                    return false;
                }
                rows[r] |= (1<< val);
                cols[c]|= (1<< val);
                squares[squareKey]|= (1<< val);
            }
        }
        return true;
    }
};
