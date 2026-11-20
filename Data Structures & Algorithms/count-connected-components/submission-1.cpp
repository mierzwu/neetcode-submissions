class Solution {
    unordered_set<int>dfs(unordered_set<int>visited, vector<vector<int>>adj, int i){
        stack<int>path;
        visited.insert(i);
        path.push(i);
        while(!path.empty()){
            int j = path.top();
            path.pop();
            for(auto& node : adj[j]){
                if(visited.find(node)==visited.end()){
                    visited.insert(node);
                    path.push(node);
                } 
            }
        }
        return visited;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int>visited;
        int count=0;
        for(int i=0;i<adj.size();i++){
            if(visited.find(i)==visited.end()){
                count++;
                visited = dfs(visited,adj,i);
            }
        }
        return count;
    }
    
};
