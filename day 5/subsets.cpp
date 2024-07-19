class Solution {
public:
    void helper(vector<int>& list, vector<int>& nums,
                vector<vector<int>>& mainlist, int i, int n) {
        if (i >= n) {
            mainlist.push_back(list);
            return;
        }
        list.push_back(nums[i]);
        helper(list, nums, mainlist, i + 1, n);
        list.pop_back();
        helper(list, nums, mainlist, i + 1, n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> list;
        vector<vector<int>> mainlist;
        helper(list, nums, mainlist, 0, n);
        return mainlist;
    }
};
