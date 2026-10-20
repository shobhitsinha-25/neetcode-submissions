class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char,int> mp;

        for(int i=0;i<tasks.size();i++)
        {
            mp[tasks[i]]++;
        }

        priority_queue<int> pq;
        for(auto [element,freq]:mp)
        {
            pq.push(freq);
        }

        queue<pair<int,int>> cooldown;

        int time=0;

        while(!pq.empty() || !cooldown.empty())
        {
            time++;

            if(!pq.empty())
            {
                int r=pq.top();
                pq.pop();
                r--;
                if(r>0) cooldown.push({r,time+n});
            }

            if(!cooldown.empty() && time==cooldown.front().second)
            {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return time;
    }
};
