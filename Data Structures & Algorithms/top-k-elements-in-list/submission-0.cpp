class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>nmap;
        vector<pair<int,int>> sorted;
        vector<int>answer;
        for(int n : nums){
            nmap[n]++;
        }
        for(auto& a : nmap){
            sorted.push_back(a);
        }
        sort(sorted.begin(), sorted.end(), [](auto& left, auto&right){
            return left.second > right.second;
        });
        for(int i = 0; i<k; i++){
            answer.push_back(sorted[i].first);
        }
        return answer;
    } 
};
