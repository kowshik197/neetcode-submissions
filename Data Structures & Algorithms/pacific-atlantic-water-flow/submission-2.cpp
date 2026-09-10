class Solution {
public:
    vector<vector<int>> dirs={{-1,0},{0,-1},{1,0},{0,1}};
    bool is_valid(vector<vector<int>>& heights, int x , int y){
        return (x>=0 && x<heights.size() && y>=0 && y<heights[0].size());
    }
    void visit(vector<vector<int>>& heights, int x, int y, vector<vector<int>>& map,int prev){
         if(map[x][y]==1) return;

        if(heights[x][y] < prev) return;

        map[x][y]=1;
        for(auto& d : dirs){
            int nr=x+d[0],nc=y+d[1];
            if(is_valid(heights,nr,nc)){
                visit(heights,nr,nc,map,heights[x][y]);

            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>> atlantic(m,vector<int>(n,-1)), pacific(m,vector<int>(n,-1));
        for(int i=0; i<m; i++){
            for(int j=0;  j<n; j++){
                if((i==0 || j==0)&& pacific[i][j]==-1){
                    visit(heights, i, j, pacific,heights[i][j]);
                }
                if((i==m-1 || j==n-1) && atlantic[i][j]==-1){
                    visit(heights,i,j, atlantic,heights[i][j]);
                }
            }
        }
        vector<vector<int>> ans;
        for(int i=0; i<m;i++){
            for(int j=0; j<n; j++){
                if(pacific[i][j]==1&& atlantic[i][j]==1) ans.push_back({i,j});
            }
        }
        return ans;
    }
};