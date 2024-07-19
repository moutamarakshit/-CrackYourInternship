class Solution {
public:
    void helper(vector<vector<int>>& ans, int i, int k, vector<int>& vec,
                vector<int>& list, int n) {
        if (list.size() == k) {
            ans.push_back(list);
            return;
        }
        for (int j = i; j < n; j++) {
            if (j > i && vec[j] == vec[j - 1])
                continue;
            list.push_back(vec[j]);
            helper(ans, j + 1, k, vec, list, n);
            list.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> vec;
        for (int i = 1; i <= n; i++)
            vec.push_back(i);
        vector<vector<int>> ans;
        vector<int> list;
        helper(ans, 0, k, vec, list, n);

        return ans;
    }
};
