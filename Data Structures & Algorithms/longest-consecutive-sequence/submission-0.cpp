class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_count=0;
        unordered_set<int> s(nums.begin(),nums.end());
        for(auto& num : nums){
            if(s.find(num-1) == s.end()){
                int i=1;
                while(s.find(num+i)!=s.end()){
                    i++;
                }
                if(i>max_count) {
                    max_count = i;
                }
            }
        }
        return max_count;
    }
};
