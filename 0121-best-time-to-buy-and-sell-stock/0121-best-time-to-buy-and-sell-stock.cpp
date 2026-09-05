class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit =0;
        int cost =0;
        int mini = prices[0];
        for(int i=0;i<n;i++){
            cost = prices[i] - mini;
            mini = min(mini,prices[i]);
            profit = max(cost,profit);
        }
        return profit;
    }
};