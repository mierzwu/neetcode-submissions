class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int v, maks=0;
        while(left < right){
            if(heights[left]>heights[right]){
                v = (heights[right] * abs(right-left));
                if(v > maks) maks = v;
                right--;
            }
            else{
                v = (heights[left] * abs(right-left));
                if( v > maks) maks = v;
                left++;
            }
        }
        return maks;

    }
};
