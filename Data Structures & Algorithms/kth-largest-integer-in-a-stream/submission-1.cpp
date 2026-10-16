class KthLargest {
    vector<int> stream;
    int m;
public:
    KthLargest(int k, vector<int>& nums) {
        m=k;
        for(int i=0;i<nums.size();i++)
        {
            stream.push_back(nums[i]);
        }
    }
    
    int add(int val) {

        stream.push_back(val);
        sort(stream.begin(),stream.end());

        return stream[stream.size()-m];
        
    }
};
