class Solution {
public:
    vector<vector<int>> dirs={{-1,0},{0,-1},{1,0},{0,1}};
    vector<vector<char>> visited;

    bool is_valid(vector<vector<int>>& grid, int x, int y){
        return (x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && visited[x][y]=='0' && grid[x][y]==1);
    }
    
    void visit(vector<vector<int>>&grid, int x, int y, int& size){
        visited[x][y]='1';
        if(grid[x][y]==1) size++;
        for(auto& d : dirs){
            int nr=x+d[0];
            int nc=y+d[1];
            if(is_valid(grid,nr,nc))
            visit(grid,nr,nc,size);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        visited.resize(grid.size(), vector<char>(grid[0].size(),'0'));
        int ans=0;
        for(int i=0; i<grid.size();i++){
            for(int j=0; j<grid[0].size();j++){
                if(visited[i][j]=='0' && grid[i][j]==1){
                    int size=0;
                    visit(grid,i,j,size);
                    ans=max(ans,size);
                }
            }
            
        }
        return ans;
    }
};