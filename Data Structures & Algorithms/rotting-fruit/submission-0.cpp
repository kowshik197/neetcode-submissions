class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
      int n = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> distance(m, vector<int>(n, -1));
        vector<vector<int>> directions = {
            {1,0},{0,1},{-1,0},{0,-1}

        };

        int fresh = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    distance[i][j]=0;
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        int ans = 0;

        while(!q.empty()){

            auto node = q.front();
            q.pop();

            int r = node.first;
            int c = node.second;

            for(auto dir : directions){


                int new_row = r + dir[0];
                int new_col = c + dir[1];
                if(new_row>=0 && new_row<m && new_col>=0 && new_col<n &&
                        grid[new_row][new_col]==1 &&
                   distance[new_row][new_col]==-1){

                    distance[new_row][new_col] = distance[r][c] + 1;
                    ans = max(ans, distance[new_row][new_col]);

                    grid[new_row][new_col]=2;
                    fresh--;
                    q.push({new_row,new_col});
                }
            }
        }

        if(fresh>0){

            return -1;

        }

        return ans;
    }
};