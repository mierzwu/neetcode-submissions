class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int diff=0, min;
        min = prices[0];
        for(int i=0; i<prices.size(); i++){
            if(prices[i]<min) min = prices[i];
            if((prices[i]-min)>diff) diff = (prices[i]-min);
        }
        
        return diff;
    }
};
