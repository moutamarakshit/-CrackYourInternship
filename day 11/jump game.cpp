class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxindex = nums[0];

        for (int i = 0; i < n; i++) {
            if (maxindex >= n - 1)
                return true;
            if (nums[i] == 0 && maxindex == i)
                return false;
            if (nums[i] + i > maxindex)
                maxindex = i + nums[i];
        }
        return true;
    }
};
