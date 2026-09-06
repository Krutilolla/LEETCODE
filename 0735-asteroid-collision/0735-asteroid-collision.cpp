class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<n;i++){
            bool destroyed = false;
            while(!st.empty() && st.top()>0 && asteroids[i]<0){
                if(st.top()< -1*asteroids[i]){
                    st.pop();
                }
                else if(st.top() == -1*asteroids[i]){
                    st.pop();
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true;
                    break;
                }
            }
            if(destroyed != true){
                st.push(asteroids[i]);
            }
        }
        int i=0;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};