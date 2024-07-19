class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& candidates, int target,
                int i, int sum, int n, vector<int>& vec) {
        if (sum == target) {
            ans.push_back(vec);
            return;
        }
        if (sum > target)
            return;
        for (int j = i; j < n; j++) {
            if (j > i && candidates[j] == candidates[j - 1])
                continue;
            vec.push_back(candidates[j]);
            helper(ans, candidates, target, j + 1, sum + candidates[j], n, vec);
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        int n = candidates.size();
        vector<int> vec;
        helper(ans, candidates, target, 0, 0, n, vec);
        return ans;
    }
};
