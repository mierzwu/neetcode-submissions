class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>nums;
        int result=0;
        for(auto& c : tokens){
            if(c=="+"){
                result = nums.top();
                nums.pop();
                result+=nums.top();
                nums.pop();
                nums.push(result);
                result=0;
            }
            else if(c=="-"){
                int temp = nums.top();
                nums.pop();
                result = nums.top();
                nums.pop();
                result = result - temp;
                nums.push(result);
                result=0;
            }
            else if(c=="*"){
                result = nums.top();
                nums.pop();
                result = result * nums.top();
                nums.pop();
                nums.push(result);
                result=0;
            
            }
            else if(c=="/" && !nums.empty()){
                int temp = nums.top();
                nums.pop();
                result = nums.top();
                nums.pop();
                result = result/temp;
                nums.push(result);
            }
            else{
                nums.push(stoi(c));
            }
            
        }
        return nums.top();
    }
};
