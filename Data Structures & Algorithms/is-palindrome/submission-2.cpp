class Solution {
public:
    bool isPalindrome(string s) {
            for (char &c : s){
                c = std::tolower(c);
            }
            int skipl = 0, skipr = s.size()-1;
            while(skipl<=skipr){
                if(!std::isalnum(s[skipl])) skipl++;
                if(!std::isalnum(s[skipr])) skipr--;
                if(std::isalnum(s[skipr]) && std::isalnum(s[skipl]) && s[skipl] == s[skipr] ) {
                    skipl++;
                    skipr--; 
                }
                if(std::isalnum(s[skipr]) && std::isalnum(s[skipl]) && s[skipl] != s[skipr] ) {
                    return false;
                }
            }
        return true;
    }
};
