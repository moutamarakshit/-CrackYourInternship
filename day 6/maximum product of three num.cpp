class Solution {
public:
    int maximumProduct(vector<int>& nums) {
       /* sort(nums.begin(),nums.end());
        int n=nums.size();
        int m1= nums[n-1]*nums[n-2]*nums[n-3];
        int m2=nums[0]*nums[1]*nums[n-1];
        if(m1>m2) return m1;
        else return m2;
        */
        int max1=INT_MIN, max2=INT_MIN, max3=INT_MIN,min1=INT_MAX, min2=INT_MAX;
        for(auto it:nums){
            if(it>max1){
                max3=max2;
                max2=max1;
                max1=it;
            }
            else if(it>max2){
                max3=max2;
                max2=it;
            }
            else if(it>max3)
                max3=it;
            
            if(it<min1){
                min2=min1;
                min1=it;
            }
            else if(it<min2){
                min2=it;
            }
        }
        return max((max1*max2*max3),(max1*min1*min2));
    }
};
