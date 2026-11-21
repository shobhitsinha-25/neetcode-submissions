class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans;

        unordered_map<int,int> mp; //element->index

        for(int i=0;i<n;i++)
        {
            int celement=target-nums[i];
            if(mp.find(celement)!=mp.end()){
                ans.push_back(mp[celement]);
                ans.push_back(i);
                break;
            } 
            else{
                mp[nums[i]]=i;
            }
        }

        return ans;

    }
};
