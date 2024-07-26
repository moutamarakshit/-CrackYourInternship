class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0, high = height.size() - 1;
        int area = 0;
        while (low <= high) {
            int mini = min(height[low], height[high]);
            int maxi = mini * (high - low);
            area = max(area, maxi);

            if (height[low] < height[high])
                low++;
            else
                high--;
        }
        return area;
    }
};
