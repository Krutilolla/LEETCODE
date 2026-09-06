class Solution {
public:
    int solve(vector<int>&cost,int idx,vector<int>&dp){
        int n = cost.size();
        if(idx>=n){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        return dp[idx]=cost[idx] + min(solve(cost,idx+1,dp),solve(cost,idx+2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        vector<int> dp(n+1,-1);
        return min(solve(cost,1,dp),solve(cost,0,dp));
    }
};