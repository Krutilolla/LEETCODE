class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string shortest = "";
        vector<string> temp;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=i;j<n;j++){
                if(s[j]=='1'){
                    count++;
                    
                }
                if(count==k){
                    string cur = s.substr(i,j+1-i);
                    if(shortest=="" || cur.size()<shortest.size() || (cur.size()==shortest.size() && cur<shortest)){
                        shortest = cur;
                    }
                }
                if(count>k){
                break;
                }
            }
        }
        return shortest;
    }
};