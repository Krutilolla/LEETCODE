class Solution {
public:
    bool checkDivisibility(int n) {
      int m = n;
      int x=0;
      int sum = 0;
      int product = 1;
      while(m>0){
        x = m%10;
        m = m/10;
        sum+=x;
        product*=x;
      }
      if(n%(sum+product)==0){
        return true;
      } 
      return false;
    }
};