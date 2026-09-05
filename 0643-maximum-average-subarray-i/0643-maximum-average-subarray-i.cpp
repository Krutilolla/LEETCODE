class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum =0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        long long maxi = sum;
        for(int i=k;i<n;i++){
            sum+= nums[i];
            sum-= nums[i-k];
            maxi = max(sum,maxi);
        }
        return double(maxi)/k;
    }
};