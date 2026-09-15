class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>answer;
        vector<string>sub;
        
        unordered_map<string, vector<string>>mp;
        for (string word : strs){
            string sorted = word;
            sort(sorted.begin(),sorted.end());
            mp[sorted].push_back(word);
        }
        for (auto& pair : mp){
            answer.push_back(pair.second);
        }
        return answer;

    }
};
