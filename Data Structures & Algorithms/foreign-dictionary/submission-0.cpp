
class Solution {
    vector<int> topoSort(int V, vector<vector<int>>& adj,
                         vector<int>& present) {

        vector<int> indegree(26, 0);

        // Calculate indegree
        for(int i = 0; i < 26; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;

        // Push only present characters with indegree 0
        for(int i = 0; i < 26; i++) {
            if(present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto it : adj[node]) {

                indegree[it]--;

                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return ans;
    }

public:
    string foreignDictionary(vector<string>& words) {

        int n = words.size();

        set<char> st;

        for(auto word : words) {
            for(auto c : word) {
                st.insert(c);
            }
        }

        int k = st.size();

        vector<int> present(26, 0);

        for(auto c : st) {
            present[c - 'a'] = 1;
        }

        vector<vector<int>> adj(26);

        // Build adjacency list
        for(int i = 0; i < n - 1; i++) {

            string s1 = words[i];
            string s2 = words[i + 1];

            int minlen = min(s1.size(), s2.size());

            // Invalid prefix case
            if(s1.size() > s2.size() &&
               s1.substr(0, s2.size()) == s2) {
                return "";
            }

            for(int x = 0; x < minlen; x++) {

                if(s1[x] != s2[x]) {

                    adj[s1[x] - 'a'].push_back(s2[x] - 'a');

                    break;
                }
            }
        }

        // Topological sort
        vector<int> ans = topoSort(k, adj, present);

        // Cycle detection
        if(ans.size() != k) {
            return "";
        }

        string ansstr = "";

        for(auto it : ans) {
            ansstr += char(it + 'a');
        }

        return ansstr;
    }
};
