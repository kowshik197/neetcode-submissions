class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int V = points.size();

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<bool> visited(V, false);

        pq.push({0, 0}); // {cost, node}

        int totalCost = 0;

        while(!pq.empty()) {

            auto [wt, node] = pq.top();
            pq.pop();

            if(visited[node])
                continue;

            visited[node] = true;

            totalCost += wt;

            // Try all points
            for(int neighbor = 0; neighbor < V; neighbor++) {

                if(!visited[neighbor]) {

                    int edgeWeight =
                        abs(points[node][0] - points[neighbor][0]) +
                        abs(points[node][1] - points[neighbor][1]);

                    pq.push({edgeWeight, neighbor});
                }
            }
        }

        return totalCost;
    }
};