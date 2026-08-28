class Solution {
public:
    bool dfs(vector<vector<int>>& graph , int node,int parent, vector<bool>& visited){
       if(visited[node]) return false;
        visited[node]=true;
        for(auto& nbr: graph[node]){
            if(nbr==parent)continue;// avoids false positive cycle detection, 
            // (0--1)node 1 has parent 0... Now from 1, we see zero also its neigbour but it is parent , avoid those case
            if(!dfs(graph,nbr,node,visited)) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
       if(edges.size()!=n-1) return false; //Cycle
       if(n==1) return true;
       vector<bool> visited(n,false);
       vector<vector<int>> graph(n);

       for(auto&e : edges){
        int u=e[0],v=e[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
       }
       if(!dfs(graph,0,-1,visited)) return false; // Checking Cycles
       for( auto v : visited) if(!v) return false;// Checking Same component or not
        return true;
    }
};