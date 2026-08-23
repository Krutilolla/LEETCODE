class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int tot1 = 0;
        int tot2 = 0;
        int count1 = 0;
        int count2 = 0;
        for(int i=0;i<n/2;i++){
            if(num[i]!='?'){
                tot1+=(num[i]-'0');
            }
            else {
                count1++;
            }
        }
        for(int i=n/2;i<n;i++){
            if(num[i]!='?'){
                tot2+=(num[i]-'0');
            }
            else {
                count2++;
            }
        }
        int diff = tot1-tot2;
        if(count1==count2){
            if(diff==0){
                return false;
            }
        }
        else if(abs(count1-count2)%2!=0){
            return true;
        }
        else{
            if((tot1-tot2)==-9*(count1-count2)/2){
                return false;
            }
            else {
                return true;
            }
        }
        return true;
    }
};