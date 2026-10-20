class Twitter {
public:
int timestamp=0;
unordered_map<int,vector<pair<int,int>>> tweets;

unordered_map<int,unordered_set<int>> following;
    Twitter() {
        timestamp=0;
        
    }
    
    void postTweet(int userId, int tweetId) {
        timestamp++;
        tweets[userId].push_back({timestamp,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int,int>> q;

        for(auto &t:tweets[userId])
        {
            q.push(t);
        }

        for(auto &f:following[userId])
        {
            for(auto &t:tweets[f])
            {
                q.push(t);
            }
        }

        while(!q.empty() && ans.size()<10)
        {
            ans.push_back(q.top().second);
            q.pop();
        }

return ans;
        
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId) return ;

        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
