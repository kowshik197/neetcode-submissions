class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int V = numCourses;
        // if(prerequisites.size()==0){
        //     vector<int> ans;
        //     for(int i=0;i<V;i++){
        //          ans.push_back(i);
        //     }
        //     return ans;
        // }

        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        vector<int> ans;

        for(auto edge : prerequisites) {

            int course = edge[0];
            int prerequisite = edge[1];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        for(int i = 0; i < V; i++) {

            if(indegree[i] == 0)
                q.push(i);
        }

        int count = 0;

        while(!q.empty()) {

            int node = q.front();
            q.pop();
            ans.push_back(node);
            count++;

            for(int neighbor : adj[node]) {

                indegree[neighbor]--;

                if(indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        if(ans.size()!=V) return {};
        return ans;

    }
};