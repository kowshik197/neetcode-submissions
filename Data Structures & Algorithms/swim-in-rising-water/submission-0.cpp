class Solution {
   public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});
        vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int cost = node[0], r = node[1], c = node[2];
            if (r == n - 1 && c == n - 1) return cost;
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                int newCost = max(cost, grid[nr][nc]);
                if (newCost < dist[nr][nc]) {
                    dist[nr][nc] = newCost;
                    pq.push({newCost, nr, nc});
                }
            }
        }
        return -1;
    }
};