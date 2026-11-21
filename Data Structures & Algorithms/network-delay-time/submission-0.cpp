
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        set<pair<int,int>> st;
        vector<int> dist(n + 1, INT_MAX);

        st.insert({0, k});
        dist[k] = 0;

        while(!st.empty()) {

            auto it = *st.begin();

            int dis = it.first;
            int node = it.second;

            st.erase(st.begin());

            for(auto neighbor : adj[node]) {

                int adjNode = neighbor.first;
                int wt = neighbor.second;

                if(dis + wt < dist[adjNode]) {

                    if(dist[adjNode] != INT_MAX) {
                        st.erase({dist[adjNode], adjNode});
                    }

                    dist[adjNode] = dis + wt;

                    st.insert({dist[adjNode], adjNode});
                }
            }
        } // while loop ends here

        // Calculate the maximum shortest distance
        int ans = 0;

        for(int i = 1; i <= n; i++) {

            if(dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
