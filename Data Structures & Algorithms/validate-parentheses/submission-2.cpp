class Solution {
public:
    bool isValid(string s) {
        stack<char> opens;
        for (char c : s){
            if(c=='(' || c=='[' || c=='{'){
                opens.push(c);
            }
            else if(!opens.empty() && c==')' && (c-1)==opens.top()) opens.pop();
            else if(!opens.empty() && (c-2)==opens.top()) opens.pop();
            else return false;
        }
        if(opens.empty()) return true;
        else return false;
    }
};
