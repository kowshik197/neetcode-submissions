//Topological Sort
class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> graph(26);
        vector<int> indegree(26,-1);
        int totunichar=0;
        for(auto& word : words){
            for(char c : word){
                if(indegree[c-'a']==-1){
                    indegree[c-'a']=0;
                    totunichar++;
                }
            }
        }
        for(int i=0; i<words.size()-1;i++){
            string w1=words[i],w2=words[i+1];
            int len=min(w1.size(),w2.size());
            if(w1.size() >w2.size() && w1.substr(0,len)==w2){
               return "";
            }
            for(int j=0;j<len;j++){
                if(w1[j]!=w2[j]){
                    graph[w1[j]-'a'].push_back(w2[j]-'a');
                    indegree[w2[j]-'a']++;
                    break;
                }
            }
        }
        string topo="";
        queue<int> zerodegree;
        
        for(int i=0; i<26; i++){
                if(indegree[i]==0) zerodegree.push(i);
        }
    

        while(!zerodegree.empty()){
            auto node=zerodegree.front();
            zerodegree.pop();
            topo+=(char)node+'a';
            for(auto&nbr : graph[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0) zerodegree.push(nbr);
            }
        }
        return topo.size()==totunichar ? topo : "";
        
    }
};