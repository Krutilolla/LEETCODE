class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int s=0;
        string ans;
        int i=9;
        if(sum > 9*num){
            return "";
        }
        while(num>0){
            int digit = min(9,sum);
            ans+=to_string(digit);
            sum-=digit;
            num--;
        }
  
        return ans;
    }
};