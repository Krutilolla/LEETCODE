class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            adj[u].push_back({v,w});
        }
        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > pq;
        const long long INF = LLONG_MAX;
        vector<vector<long long>>dist(n,vector<long long>(k+1,INF));
        dist[0][1] = 0;

        pq.push({0,0,1});
        while(!pq.empty()){
            auto[d, node, count] = pq.top();
            
            pq.pop();
            if(d!=dist[node][count]) continue;
            for(auto it : adj[node]){
                int edgewt = it.second;
                int adjnode = it.first;
                int newcnt;
                if(labels[node] == labels[adjnode]){
                    newcnt = count+1;
                }
                else{
                    newcnt = 1;
                }
                if(newcnt > k) continue;

                if(d + edgewt < dist[adjnode][newcnt]) {

                    dist[adjnode][newcnt] = d + edgewt;

                    pq.push({dist[adjnode][newcnt], adjnode, newcnt});
                }
            }
        }
        long long ans = INF;
        for(int i = 1; i <= k; i++) {
            ans = min(ans, dist[n-1][i]);
        }

        return ans == INF ? -1 : ans;
    }
};