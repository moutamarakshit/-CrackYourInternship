class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0, count = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        for (auto it : nums) {
            sum += it;
            int rem = (sum % k + k) % k;
            if (mpp.find(rem) != mpp.end())
                count += mpp[rem];
            mpp[rem]++;
        }
        return count;
    }
};
