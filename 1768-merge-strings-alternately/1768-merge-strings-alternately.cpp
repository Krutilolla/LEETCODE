class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        string s;
        int i=0;
        int j=0;
        while(i<n1 || j<n2){
            if(i<n1){
                s.push_back(word1[i]);
                i++;
            }
            if(j<n2){
                s.push_back(word2[j]);
                j++;
            }
        }
        return s;
    }
};