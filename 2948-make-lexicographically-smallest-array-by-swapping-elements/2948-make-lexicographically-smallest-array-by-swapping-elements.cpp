class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> ans(n);
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        int i=0;
        while(i<n){
            int j = i;
            while(j+1<n && arr[j+1].first-arr[j].first<=limit){
            j++;
            }
            vector<int> idx;
            for(int k=i;k<=j;k++){
                idx.push_back(arr[k].second);
            }
            sort(idx.begin(),idx.end());
            for(int k=0;k<idx.size();k++){
                ans[idx[k]] = arr[i+k].first;
            }
            i = j+1;
        }
        return ans;
    }
};