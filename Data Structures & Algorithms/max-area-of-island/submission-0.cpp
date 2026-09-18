
class Solution {
      int dx[4]= {1,-1,0,0};
    int dy[4]={0,0,1,-1};
    private:
void dfs(int r,int c, int & n , int &m , vector<vector<int>>&grid,vector<vector<bool>>&vis ,int& val){
    if(r<0 || r>=n || c<0 || c>=m)return ;
    if(grid[r][c]==0)return ;
    vis[r][c]=true;
    val++;
    for(int i=0;i<4;i++){
        int new_r=r+dx[i],new_c=c+dy[i];
        if(new_r>=0 && new_r<n && new_c<m  && new_c>=0 &&  grid[new_r][new_c] ==1 && !vis[new_r][new_c]){
            dfs(new_r,new_c,n,m,grid,vis,val);
        }
    }
    // return 0;
}
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
          int islands= 0;
        int n = grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int max_area=0;
        for(int r=0;r<n;r++){

            for(int c =0 ;c<m;c++){

                if( grid[r][c]==1 && vis[r][c]==false ){
                    int val=0;
                    islands++;
                    dfs(r,c,n,m,grid,vis,val);
                    max_area=max(val,max_area);
                }
            }
        }
        cout << islands << endl;
        return max_area;
    }
};
