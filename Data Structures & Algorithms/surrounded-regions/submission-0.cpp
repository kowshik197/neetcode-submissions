class Solution {
public:
     vector<vector<int>> dirs={{-1,0},{0,-1},{1,0},{0,1}};
    bool is_valid(vector<vector<char>>& board, int x, int y){
        return (x>=0 && x<board.size() && y>=0 && y<board[0].size());
    }
    void invalidate(vector<vector<char>>& board, int x, int y){
        board[x][y]='I';
        for(auto&d : dirs){
            int nr=x+d[0];
            int nc=y+d[1];
            if(is_valid(board,nr,nc)&& board[nr][nc]=='O'){
                invalidate(board,nr,nc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0||i==m-1||j==0||j==n-1){
                    if(board[i][j]=='O')
                        invalidate(board, i, j);
                }
            }
        }
        // after invalidating make all Os to be X ( they are surroundable)
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='I') board[i][j]='O';
               else if(board[i][j]=='O') board[i][j]='X';
            }
        }
        
    }
};