class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int mini = INT_MAX;
        for(int i=l;i<=r;i++){
            for(int j=0;j<=n-i;j++){
                int sum=0;
                for(int k=j;k<j+i;k++){
                    sum+=nums[k];
                }
                if(sum>0 && sum<mini){
                    mini = sum;
                }
            }
        }
        if(mini == INT_MAX){
            return -1;
        }
        return mini;
    }
};