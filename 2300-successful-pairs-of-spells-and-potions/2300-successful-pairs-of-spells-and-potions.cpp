class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> ans;
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++){
            int low = 0;
            int high = m-1;
            while(low<=high){
                int mid = low+(high-low)/2;
                if(1LL*spells[i]*potions[mid]<success){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            int count = m-low;
            ans.push_back(count);
        }
        
        return ans;
    }
};