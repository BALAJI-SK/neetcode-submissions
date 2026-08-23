class Solution {
    private:
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,-1,1};
    bool backtrack(vector<vector<char>>& board, vector<vector<bool>>& mask,string & word,int n ,int m , int row,int col ,int index){
        if(index==word.size()-1)return true;
        if(row>=n || col>=m)return false;
        bool val=false;
        // if(word[index]!=board[row][col])return false;
        for(int i=0;i<4;i++){
            int nRow= dx[i]+row;
            int nCol = dy[i]+col;
            if(nRow>=0 && nCol>=0 && nRow<n && nCol<m && !mask[nRow][nCol]&&word[index+1]==board[nRow][nCol]){
                mask[nRow][nCol]=true;
               //cout << nRow << " "<< nCol<<endl;
                val |=backtrack(board,mask,word,n,m,nRow,nCol,index+1);
                 mask[nRow][nCol]=false;
            }
            if(val)return true;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        vector<vector<bool>>mask(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    mask[i][j]=true;
                    bool val = backtrack(board,mask,word,n,m,i,j,0);
                    mask[i][j]=false;
                if(val)return true;
                }
            }
        }
        return false;
    }
};
