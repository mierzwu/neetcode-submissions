class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp;
        int left=0;
        int right=0;
        int count=0;
        for(auto& c : s1) mp[c]++;
        for(right; right<s2.size(); right++){
            if(mp.find(s2[right])!=mp.end() && mp[s2[right]]>0){
                mp[s2[right]]--;
                count++;
                if(count==s1.size()) return true; 
            }
            else if(left < right){
                if(mp.find(s2[left])!=mp.end()){
                    count --;
                    mp[s2[left]]++;
                } 
                left++;
                right--;
            }
        }
        return false;
    }
};
