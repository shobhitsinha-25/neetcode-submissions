class Solution {
public:
unordered_map<string,priority_queue<string,vector<string>,greater<string>>> adj;

vector<string> ans;

void dfs(string node)
{
    while(!adj[node].empty())
    {
        string nextnode=adj[node].top();
        adj[node].pop();
        dfs(nextnode);
    }
    ans.push_back(node);
}

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto ticket:tickets)
        {
            adj[ticket[0]].push(ticket[1]);
        }

        dfs("JFK");

        reverse(ans.begin(),ans.end());
        return ans;


    }
};
