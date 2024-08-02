class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        for (auto it : nums)
            mpp[it]++;
        priority_queue<pair<int, int>> pq;
        for (auto it : mpp) {
            pq.push({it.second, it.first});
        }
        vector<int> vec;
        while (k != 0) {
            vec.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return vec;
    }
};
