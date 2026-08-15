class Solution {
public:
    void dfs(int node,vector<vector<int>>& graph,vector<bool>& visited){
        
        visited[node]=true;

        for(int nbr: graph[node]){
            if(!visited[nbr]){
                dfs(nbr,graph,visited);
            }
        }

    }

    int countComponents(int n, vector<vector<int>>& edges) {

       vector<bool> visited(n,false);
       vector<vector<int>> graph(n);
       int count=0;

       for(auto&e : edges){
        int u=e[0],v=e[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
       }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            count++;
            dfs(i,graph,visited);
        }

        
    }

    return count;

    }


};
