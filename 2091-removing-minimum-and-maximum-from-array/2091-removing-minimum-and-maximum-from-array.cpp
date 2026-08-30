class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        int idxmini=0;
        int idxmaxi=0;
        bool frontmin = false;
        bool frontmax = false;
        for(int i=0;i<n;i++){
            if(nums[i]==mini){
                idxmini = min(i,n-1-i);
                if(idxmini == i){
                    frontmin =true;
                }
                else {
                    frontmin = false;
                }
            }
            if(nums[i]==maxi){
                idxmaxi = min(i,n-1-i);
                if(idxmaxi == i){
                    frontmax = true;
                }
                else{
                    frontmax = false;
                }
            }
        }
        if((frontmin== true && frontmax == true)|| (frontmin== false && frontmax == false) ){
            return max(idxmini , idxmaxi)+1;
        }
        else if((frontmin == true && frontmax == false) || (frontmin == false && frontmax == true)){
            int k= min(idxmini+idxmaxi+2,max(idxmini,n-1-idxmaxi)+1);
            return min(k,max(-idxmini+n-1,idxmaxi)+1);
        }
        return 0;
    }
};
