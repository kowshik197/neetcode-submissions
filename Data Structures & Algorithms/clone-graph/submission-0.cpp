/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
    Node* dfs(Node* node, unordered_map<Node*,Node*>& mp){
        if(mp.find(node)!=mp.end()) return mp[node];
        Node* newnode= new Node(node->val);
        mp[node]=newnode;
        for(Node* nbr : node->neighbors){
            newnode->neighbors.push_back(dfs(nbr,mp));
        }
        return newnode;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(node==NULL) return NULL;
        return dfs(node,mp);
        
    }
};