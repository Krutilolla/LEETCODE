class Solution {
public:  
    void solve(vector<vector<int>>& grid,int i,int j, int x, vector<vector<vector<bool>>> &dp){
        int n = grid.size();
        int m = grid[0].size();

        if(i>=n || j>=m){
            return ;
        }
        x^=grid[i][j];
        if(dp[i][j][x]) return;
        dp[i][j][x] = true;
        if(i<=n-1){
            solve(grid,i+1,j,x,dp);
        }
        if(j<=m-1){
            solve(grid, i,j+1,x,dp);
        }
    }
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<bool>>> dp(n,vector<vector<bool>>(m,vector<bool>(1024,false)));
        solve(grid,0,0,0,dp);
        for(int x=0;x<1024;x++){
            if(dp[n-1][m-1][x]) return x;
        }
        return -1;
    }
};