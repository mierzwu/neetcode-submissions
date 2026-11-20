class Solution {
    set<pair<int,int>>visited;
    stack<pair<int,int>>path;
    int count=0;
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(visited.find({i,j})==visited.end() && grid[i][j]=='1') {
            path.push({i,j});
            count++;
        }
        while(!path.empty()){
            i = path.top().first;
            j = path.top().second;
            path.pop();
            visited.insert({i,j});
            if(i>0 && grid[i-1][j]=='1' && visited.find({i-1,j})==visited.end()) path.push({i-1,j});
            if(i<grid.size()-1 && grid[i+1][j]=='1' && visited.find({i+1,j})==visited.end()) path.push({i+1,j});
            if(j>0 && grid[i][j-1]=='1' && visited.find({i,j-1})==visited.end()) path.push({i,j-1});
            if(j<grid[0].size()-1 && grid[i][j+1]=='1' && visited.find({i,j+1})==visited.end()) path.push({i,j+1});
        }
        
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        for(int i=0; i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                dfs(grid,i,j);
            }
        }
        return count;
    }
};
