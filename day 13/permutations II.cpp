class Solution {
public:
    void helper(vector<int>& vis, int n, vector<int>& vec, set<vector<int>>& st,
                vector<int>& nums) {
        if (vec.size() == n) {
            st.insert(vec);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vis[i] = 1;
                vec.push_back(nums[i]);
                helper(vis, n, vec, st, nums);
                vis[i] = 0;
                vec.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n, 0);
        set<vector<int>> st;
        vector<int> vec;
        helper(vis, n, vec, st, nums);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
