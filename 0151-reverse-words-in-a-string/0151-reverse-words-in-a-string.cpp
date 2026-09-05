class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string> ans;
        string str;
        for(int i=0;i<n;i++){
            while(i<n && s[i]!=' '){
                str+=s[i];
                i++;
            }
            if(str!=""){
                    ans.push_back(str);
                    str = "";
            }
        }
        int m = ans.size();
        string final;
        for(int i=m-1;i>=0;i--){
            final += ans[i];
            if(i!=0){
                final += " ";
            }
        }
        return final;
    }
};