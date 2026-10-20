class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int,int>>>,
    greater<pair<int, pair<int, int>>>
> q;

vector<vector<int>> ans;

for(int i=0;i<p.size();i++)
{
    int x=p[i][0];
    int y=p[i][1];
    int distance=x*x+y*y;

    q.push({distance,{x,y}});
}

for(int i=0;i<k;i++)
{
    int x=q.top().second.first;
    int y=q.top().second.second;
    q.pop();
    vector<int> temp;
    temp.push_back(x);
    temp.push_back(y);
    ans.push_back(temp);
}

return ans;

    }
};
