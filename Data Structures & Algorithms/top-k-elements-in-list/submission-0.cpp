class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> q;
        vector<int> ans;
        map<int,int> freq;

        for(auto it:nums)
        {
            freq[it]++;
        }

        for(auto it:freq)
        {
            q.push({it.second,it.first});
        }

        for(int i=0;i<k;i++)
        {
            ans.push_back(q.top().second);
            q.pop();
        }

        return ans;
    }


};
