class Solution {
public:
    
    string encode(vector<string>& strs) {
        string s;
        for(auto& str : strs){
            s += to_string(str.size()) + ',' + str;
        }
        return s;
    }
    vector<string> decode(string s) {
        string sub, size_str;
        int count = -1;
        vector<string> answer;
        for(int i = 0; i < s.size(); i++){
            if(count == -1) {
                if(s[i] == ',') {
                    int size = std::stoi(size_str);
                    size_str = ""; 
                    count = size;
                    if(count == 0) {
                        answer.push_back("");
                        count = -1;
                    }
                } 
                else size_str += s[i];
            } 
            else {
                sub += s[i];
                count--;
                if(count == 0) {
                    answer.push_back(sub);
                    sub = "";
                    count = -1;
                }
            }
        }
        return answer;
    }
};
