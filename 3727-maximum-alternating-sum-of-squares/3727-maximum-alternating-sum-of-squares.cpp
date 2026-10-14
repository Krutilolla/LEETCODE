class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> n1;
        vector<int> n2;
        long long ans=0;
        for(int i=0;i<n;i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n/2;i++){
            n2.push_back(nums[i]);
        }
        for(int i=n/2;i<n;i++){
            n1.push_back(nums[i]);
        }

        for(int i=0;i<n/2;i++){
            ans += 1LL * n1[i]*n1[i] - 1LL*n2[i]*n2[i];
        }
        if(n%2!=0){
            ans+=1LL*n1[n/2]*n1[n/2];
        }
        return ans;
    }
};