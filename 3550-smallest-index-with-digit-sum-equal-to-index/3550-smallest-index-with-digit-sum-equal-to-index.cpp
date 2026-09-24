class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        if(nums[0]==0){
            return 0;
        }
        for(int i=0;i<n;i++){
            int sum=0;
            int x = nums[i];
            while(x>0){
                
                int rem = x%10;
                sum+=rem; 
                x = x/10;
            }
            if(i == sum){
                return i;
            }
        }
        return -1;
    }
};