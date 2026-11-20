class Solution {
    
    pair<int,int> dfs(vector<vector<int>>& heights,int i, int j){
        stack<pair<int,int>>path;
        pair<int,int>start = {i,j};
        set<pair<int,int>>visited;
        path.push(start);
        visited.insert(start);
        bool p=false;
        bool a=false;
        while(!path.empty()){
            i = path.top().first;
            j = path.top().second;
            path.pop();

            if(i==0 || j==0) p=true;
            if(i==heights.size()-1 || j==heights[0].size()-1) a=true;
            if(i>0 && heights[i-1][j]<=heights[i][j] && visited.find({i-1,j})==visited.end()){
                path.push({i-1,j});
                visited.insert({i-1,j});
            }
            if(j>0 && heights[i][j-1]<=heights[i][j] && visited.find({i,j-1})==visited.end()){
                path.push({i,j-1});
                visited.insert({i,j-1});
            }
            if(i<heights.size()-1 && heights[i+1][j]<=heights[i][j] && visited.find({i+1,j})==visited.end()){
                path.push({i+1,j});
                visited.insert({i+1,j});
            }
            if(j<heights[0].size()-1 && heights[i][j+1]<=heights[i][j] && visited.find({i,j+1})==visited.end()){
                path.push({i,j+1});
                visited.insert({i,j+1});
            }
            if(p&&a) return start;
        }
        return{-1,-1};
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>answer;
        pair<int,int>answerDfs;
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                answerDfs = dfs(heights,i,j);
                if(answerDfs.first!=-1){
                    vector<int>answer1;
                    answer1.push_back(answerDfs.first);
                    answer1.push_back(answerDfs.second);
                    answer.push_back(answer1);
                }
            }
        }
        return answer;
    }
};
