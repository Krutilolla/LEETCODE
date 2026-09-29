class Solution {
public:

    bool solve(vector<vector<char>>& grid, int i, int j, int balance,vector<vector<vector<int>>> &dp){
        int n = grid.size();
        int m = grid[0].size();
        if(i>=n || j>=m){
            return false;
        }
        if(grid[i][j]=='('){
            balance++;
        }
        else {
            balance--;
        }
        if(balance < 0){
            return false;
        }
        if(i==n-1 && j==m-1){
            return balance ==0;
        }
        if(dp[i][j][balance]!=-1){
            return dp[i][j][balance];
        }
        bool down= solve(grid, i+1,j,balance,dp);
        bool right= solve(grid, i,j+1,balance,dp);
        return dp[i][j][balance] = down || right;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int len = m+n-1;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(len + 1, -1)));
        if(len%2!=0){
            return false;
        }
        return solve(grid,0,0,0,dp);
    }
};