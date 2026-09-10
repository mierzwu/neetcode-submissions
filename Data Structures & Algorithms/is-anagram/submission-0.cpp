class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> smap;
        unordered_map<char,int> tmap;

        if(s.size()==t.size()){
            for(int i=0; i<s.size(); i++){
                smap[s[i]]++;
                tmap[t[i]]++;
            }
            if(smap==tmap) return true;
        }
        return false;
    }
};
