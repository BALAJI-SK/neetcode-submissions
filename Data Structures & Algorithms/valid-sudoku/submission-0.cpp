class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int n=board.size();
        for(int i=0;i<n;i++){
            unordered_set<int>row,col,square;
            
            for(int j=0;j<n;j++){
                int val =board[i][j]=='.'?-1:board[i][j]-'0';
                if(val!=-1){
                if(row.find(val)!=row.end()){
                    //  cout << val<<" ";
                    return false;
                }else{
                    row.insert(val);
                }
                }
            }
          //  cout << "row"<<endl;
            for(int j=0;j<n;j++){
                 int val =board[j][i]=='.'?-1:board[j][i]-'0';
                   if(val!=-1){
                if(col.find(val)!=col.end()){
                    return false;
                }else{
                    col.insert(val);
                }
                   }
            }
               //cout << "col"<<endl;
            int rowAdd = (i/3)*3,colAdd=(i%3)*3;
            for(int k=0;k<3;k++)
            for(int j=0;j<3;j++){
                int val = board[rowAdd+k][colAdd+j]=='.'?-1:board[rowAdd+k][colAdd+j]-'0';
                 if(val!=-1){
                   if(square.find(val)!=square.end()){
                    return false;
                }else{
                    square.insert(val);
                }
            }
            }
               //cout << "sqaure"<<endl;
        }
        return true;
    }
};
