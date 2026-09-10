class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> numbers;
        for(int i : nums){
            numbers.insert(i);
        }
        if(nums.size()>numbers.size()) return true;
        else return false;
    }
};