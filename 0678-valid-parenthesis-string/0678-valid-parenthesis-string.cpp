class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int mini = 0;
        int maxi=0;
        if(s[0]==')'){
            return false;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                mini++;
                maxi++;
            }
            else if(s[i] == '*'){
                mini = mini-1;
                maxi = maxi+1;
            }
            else if(s[i]==')'){
                mini--;
                maxi--;
            }
            mini = max(mini,0);
            if(maxi<0){
                return false;
            }
        }
        
        if(mini == 0){
            return true;
        }
        return false;
    }
};