class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum1 = 0, sum2 = 0;
        int n = cardPoints.size();
        for (int i = 0; i < k; i++) {
            sum1 += cardPoints[i];
        }
        int maxsum = sum1;
        for (int i = 0; i < k; i++) {
            sum1 = sum1 - cardPoints[k - i - 1];
            sum2 += cardPoints[n - i - 1];
            maxsum = max(sum1 + sum2, maxsum);
        }
        return maxsum;
    }
};
