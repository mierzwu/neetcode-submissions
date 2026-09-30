class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int lwall=left, rwall=right;
        int answer=0;
        while(left<right){
            if(height[rwall]>=height[lwall]) {
                left++;
                if(height[left]>height[lwall]) lwall = left;
                else answer+=(height[lwall]-height[left]);
            }
            else {
                right--;
                if(height[right]>height[rwall]) rwall = right;
                else answer+=(height[rwall]-height[right]);
            }
        }
        return answer;
    }
};
