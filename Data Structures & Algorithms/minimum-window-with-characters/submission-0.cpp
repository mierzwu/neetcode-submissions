class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int count = t.size();
        int min_window = s.size()+1;
        bool happend = false;
        int answer_start=0;
        int answer_end=0;
        string answer = "";
        unordered_map<char, int>mp;
        for(auto& c : t){
            mp[c]++;
        }
        for(int right=0; right<s.size(); right++){
            if(mp.find(s[right])!=mp.end()){
                if(mp[s[right]]>0) count--;
                mp[s[right]]--;
            }   
            while(count==0){
                if(mp.find(s[left])!=mp.end()){
                    happend = true;
                    if(min_window > (right-left+1)){
                        answer_start = left;
                        answer_end = right;
                        min_window = (right-left+1);
                    }
                    if((mp[s[left]]+1)>0) count++;
                    mp[s[left]]++;
                }
                left++;
            }          
        }
        if(happend){
            for(int i = answer_start; i<=answer_end; i++){
                answer += s[i];
            }
            return answer;
        }
        else return answer;
    }
};
