class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int n = s.size();
        string ans;
        for(int i=0;i<n;i++){
            if(!st.empty()){
                if(s[i]=='*'){
                    st.pop();
                }
            }
            if(s[i]!='*'){
                st.push(s[i]);
            }
        }
        int i=0;
        while(!st.empty()){
            ans+= st.top();
            st.pop();
            i++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};