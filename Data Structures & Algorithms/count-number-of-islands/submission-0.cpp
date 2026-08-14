class Solution {
public:

    class DSU {
    public:
        vector<int> parent;
        vector<int> size;
        int comp;

        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);
            comp = 0;

            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        void addLand() {
            comp++;
        }

        int find(int x) {
            if (parent[x] == x)
                return x;

            return parent[x] = find(parent[x]);
        }

        bool unite(int a, int b) {

            a = find(a);
            b = find(b);

            if (a == b)
                return false;

            if (size[a] < size[b])
                swap(a, b);

            parent[b] = a;
            size[a] += size[b];

            comp--;

            return true;
        }
    };


    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        DSU dsu(m * n);

        // Step 1: Every land cell is initially
        // considered as a separate island
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '1') {
                    dsu.addLand();
                }
            }
        }


        // Step 2: Connect adjacent land cells
        // Only RIGHT and DOWN are needed
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '0')
                    continue;

                int curr = i * n + j;


                // RIGHT
                if (j + 1 < n && grid[i][j + 1] == '1') {

                    int right = i * n + (j + 1);

                    dsu.unite(curr, right);
                }


                // DOWN
                if (i + 1 < m && grid[i + 1][j] == '1') {

                    int down = (i + 1) * n + j;

                    dsu.unite(curr, down);
                }
            }
        }

        return dsu.comp;
    }
};
// class Solution {
// public:
//     bool is_valid(vector<vector<char>>& grid,vector<vector<bool>>& visited, int x, int y){
//         return (x>=0 && x<grid.size() && y>=0 && y<grid[0].size()&&!visited[x][y] && grid[x][y]=='1');
//     }
//     void visit(vector<vector<char>>& grid,vector<vector<bool>>& visited, int x, int y, vector<vector<int>>& dirs){
//         visited[x][y]=true;
//         for(auto d : dirs){
//             int nr=x+d[0];
//             int nc=y+d[1];
//             if(is_valid(grid,visited,nr,nc)){
//                 visit(grid,visited,nr,nc,dirs);
//             }
//         }
//     }

//     int numIslands(vector<vector<char>>& grid) {
//         vector<vector<int>> dirs={{-1,0},{0,-1},{1,0},{0,1}};
//         vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size()));
//         int count=0;
//         for(int i=0; i<grid.size(); i++){
//             for(int j=0; j<grid[0].size(); j++){
//                 if(!visited[i][j]&& grid[i][j]=='1'){
//                     visit(grid,visited,i,j,dirs);
//                     count++;
//                 }

//             }
//         }
//         return count;
        
//     }
// };
