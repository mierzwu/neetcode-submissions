class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>answer;
        int i=0;
        int j = numbers.size()-1;
        while(true){
            if(numbers[i]+numbers[j]>target){
                j--;
            }
            if(numbers[i]+numbers[j]<target){
                i++;
            }
            if(numbers[i]+numbers[j]==target){
                answer.push_back(i+1);
                answer.push_back(j+1);
                return answer;
            }
        }
                
        

    }
};
