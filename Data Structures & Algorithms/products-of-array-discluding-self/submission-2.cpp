class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int factorial=1;
        int zero_count=0;
        vector<int>answer;
        for(auto& num : nums){
            if(num != 0) {
                factorial *= num;
            }
            else zero_count++;
        }
        for(auto& num : nums){
            if(num == 0 && zero_count<=1) answer.push_back(factorial);
            else if(num != 0 && zero_count==1) answer.push_back(0);
            else if (zero_count>1) answer.push_back(0);
            else answer.push_back((factorial/num));
        }
        return answer;
    }
};
