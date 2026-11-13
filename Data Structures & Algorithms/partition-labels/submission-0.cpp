class Solution {
public:
    vector<int> partitionLabels(string s) {

        unordered_map<char, pair<int,int>> mp;

        // Step 1: Store first and last occurrence
        for(int i = 0; i < s.size(); i++) {

            if(mp.find(s[i]) == mp.end()) {
                mp[s[i]] = {i, i};
            }
            else {
                mp[s[i]].second = i;
            }
        }

        // Step 2: Merge overlapping intervals
        vector<pair<int,int>> intervals;

        for(auto x : mp) {
            intervals.push_back(x.second);
        }

        // Step 3: Sort intervals by starting index
        sort(intervals.begin(), intervals.end());

        vector<int> ans;

        int start = intervals[0].first;
        int end = intervals[0].second;

        for(int i = 1; i < intervals.size(); i++) {

            if(intervals[i].first <= end) {
                end = max(end, intervals[i].second);
            }
            else {
                ans.push_back(end - start + 1);

                start = intervals[i].first;
                end = intervals[i].second;
            }
        }

        ans.push_back(end - start + 1);

        return ans;
    }
};