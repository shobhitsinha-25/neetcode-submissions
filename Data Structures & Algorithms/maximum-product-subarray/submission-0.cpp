class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();

        vector<int> dpmax(n);
        vector<int> dpmin(n);

        int ans=nums[0];
        dpmax[0]=nums[0];
        dpmin[0]=nums[0];

        for(int i=1;i<n;i++)
        {
            int a=nums[i];
            int b=nums[i]*dpmax[i-1];
            int c=nums[i]*dpmin[i-1];

            dpmax[i]=max({a,b,c});
            dpmin[i]=min({a,b,c});

            ans=max(dpmax[i],ans);
        }

        return ans;
    }
};
