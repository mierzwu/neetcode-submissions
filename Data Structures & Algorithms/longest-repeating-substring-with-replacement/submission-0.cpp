class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>a;
        int left=0;
        int right=0;
        int c_max=0;
        int answer=0;
        for(right; right<s.size(); right++){
            a[s[right]]++;
            c_max = max(c_max, a[s[right]]);
            while(((right-left+1)-c_max)>k){
                a[s[left]]--;
                left++;
            }
            answer = max(answer, right-left+1);

        }
        return answer;
    }
};
