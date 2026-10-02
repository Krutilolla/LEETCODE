class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        Parenthesis(0,0,n,"",ans);
        return ans;
    }
    void Parenthesis(int open, int close, int n, string s,vector<string>&ans){
       if(s.size()==2*n){
        ans.push_back(s);
        return ;
       } 
       if(open<n){
        Parenthesis(open+1,close,n,s+'(',ans);
       }
       if(close<open){
        Parenthesis(open,close+1,n,s+')',ans);
       }
    }
    };