class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int mini=intervals[0][0];
        int maxi=intervals[0][1];

        for(int i=1;i<intervals.size();i++)
        {
            int f=intervals[i][0];
            int s=intervals[i][1];

            if(f<=maxi && s>=maxi) maxi=s;
            else if(f<=maxi && s<=maxi) continue; 
            else{
                ans.push_back({mini,maxi});
                mini=f;maxi=s;
            }
        }
        ans.push_back({mini,maxi});

        return ans;
    }
};
