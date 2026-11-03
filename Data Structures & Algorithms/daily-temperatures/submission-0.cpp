class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>temp;
        vector<int>answer(temperatures.size(), 0);
        for(int i=0; i<temperatures.size(); i++){
            int t = temperatures[i];
            while(!temp.empty() && t > temp.top().first){
                auto pair = temp.top();
                temp.pop();
                answer[pair.second] = i-pair.second;
            }
            temp.push({t,i});
        }
        return answer;

    }
};
