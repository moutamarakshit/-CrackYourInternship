class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        sort(nums.begin(), nums.end());
        int moves = 0;
        while (low < high) {
            moves += abs(nums[high] - nums[low]);
            low++;
            high--;
        }
        return moves;
    }
};
