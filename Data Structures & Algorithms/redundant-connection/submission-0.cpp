class Solution {


public:

    class DSU{

public:

    vector<int> parent;
    vector<int> size;

    DSU(int n){

        parent.resize(n);
        size.resize(n,1);

        for(int i=0;i<n;i++)
            parent[i]=i;
    }

    int find(int x){

        if(parent[x]==x)
            return x;

        return parent[x]=find(parent[x]);
    }

    bool Union(int a,int b){

        a=find(a);
        b=find(b);

        // Already connected
        if(a==b)
            return false;

        if(size[a]<size[b])
            swap(a,b);

        parent[b]=a;
        size[a]+=size[b];

        return true;
    }
};
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

    int n = edges.size();
    DSU dsu(n + 1);

    for(auto &e : edges){

        if(!dsu.Union(e[0], e[1]))
            return e;
    }

    return {};
}
};