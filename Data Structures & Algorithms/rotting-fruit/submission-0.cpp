class Solution {
    bool check(int & new_x,int &new_y,int n,int m){
        return (new_x>=0 && new_y>=0 && new_x<n && new_y<m);
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
      int time=0,fresh=0,n=grid.size(),m=grid[0].size();
      queue<pair<int,int>>q;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1)
            {
                fresh++;
            }else if(grid[i][j]==2){
                q.push({i,j});
            }
        }
      }
      int dx[]={0,0,-1,1};
      int dy[]={1,-1,0,0};
      while(!q.empty() && fresh>0){
        int size =q.size();
        time++;
        while(size){
            auto cell = q.front();
            q.pop();size--;
            for(int i=0;i<4;i++){
                int new_x=cell.first+dx[i];
                int new_y=cell.second+dy[i];
                if(check(new_x,new_y,n,m) && grid[new_x][new_y]==1 ){
                    fresh--;
                   grid[new_x][new_y]=2;
                   q.push({new_x,new_y}); 
                }
            }
        }
      }
      return fresh?-1:time;  
    }
};
