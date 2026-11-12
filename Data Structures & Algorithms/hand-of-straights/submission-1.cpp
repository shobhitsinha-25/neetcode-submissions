class Solution {
public:
    bool isNStraightHand(vector<int>& h, int groupSize) {
        //sort(h.begin(),h.end());
        if(h.size()%groupSize!=0) return false;
        int n=h.size();
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[h[i]]++;
        }

        for(auto x:mp)
        {
            int num=x.first;
            int numfreq=x.second;
            
            if(numfreq>0)
            {
            for(int i=0;i<groupSize;i++)
            {
                if(mp[num+i]<numfreq) return false;
                mp[num+i]-=numfreq;

            }
            }
        }

        return true;

       

    }
};
