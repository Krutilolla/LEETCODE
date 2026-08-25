class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        int i=1;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        while(i>0){
            int m = k*i;
            if(mp.find(m)==mp.end()){
                return m;
            }
            i++;
        }
        return -1;
    }
};