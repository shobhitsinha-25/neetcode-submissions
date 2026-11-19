class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int n=pre.size();
        int m=pre[0].size();
        vector<vector<int>> adj(numCourses);

        for(auto it:pre)
        {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> indegree(numCourses,0);
        queue<int> q;
        vector<int> topo;

        for(int i=0;i<numCourses;i++)
	    {
	        for(auto it:adj[i])
	        {
	            indegree[it]++;
	        }
	    }

        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0) q.push(i);
            
        }

        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);

            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        return (topo.size()==numCourses)?true:false;

    }
};
