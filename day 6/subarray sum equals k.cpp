class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        /*int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=nums[i];
            if(sum==k) count++;
            for(int j=i+1;j<n;j++){
                sum+=nums[j];
                if(sum==k)
                count++;
            }
        }
        return count;
    }
    */
        int sum = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        for (auto it : nums) {
            sum += it;
            if (mpp.find(sum - k) != mpp.end())
                count += mpp[sum - k];
            mpp[sum]++;
        }
        return count;
    }
};
