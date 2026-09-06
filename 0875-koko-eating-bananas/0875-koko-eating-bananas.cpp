class Solution {
public:

    long long totalhours(vector<int>&nums, int k){
        long long total = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            total+= ceil((double)nums[i]/double(k));
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid = low+(high-low)/2;
            if(totalhours(piles,mid)<=h){
                high = mid-1;
            }
            else {
                low = mid+1;
            }

        }
        return low;
    }
};