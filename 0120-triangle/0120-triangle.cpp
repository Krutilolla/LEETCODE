class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       int n = triangle.size();
       int m = triangle[0].size();
       vector<vector<int>> dp(n);
       for(int i=0;i<n;i++){
        dp[i].resize(triangle[i].size());
       }
       for(int i =0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(i==0 && j==0) {
                    dp[i][j] = triangle[i][j];
                    continue;
                }
                int up = triangle[i][j];
                if(i>0 && j<triangle[i-1].size()) up+=dp[i-1][j];
                else up+=1e9;
                int up_left = triangle[i][j];
                if(j>0 && i>0) up_left +=dp[i-1][j-1];
                else up_left+=1e9;
                dp[i][j] = min(up,up_left);
            }
       }
       int ans = INT_MAX;
       for(int i=0;i<triangle[n-1].size();i++){
            ans = min(ans,dp[n-1][i]);
       }
       return ans;
    }
};