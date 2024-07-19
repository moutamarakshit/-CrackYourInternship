class Solution {
public:
    void helper(set<vector<int>>& st, vector<int>& nums, vector<int>& vec, int i) {
        if (i == nums.size()) {
            st.insert(vec);
            return;
        }
        vec.push_back(nums[i]);
        helper(st, nums, vec, i + 1);
        vec.pop_back();
        helper(st, nums, vec, i + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        vector<int> vec;
        helper(st, nums, vec, 0);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
