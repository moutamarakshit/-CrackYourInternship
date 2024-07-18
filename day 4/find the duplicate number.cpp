class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /* map<int,int>mp;
        for(auto it:nums){
            mp[it]=mp[it]+1;
            if(mp[it]==2) return it;
        }
        return 0; */
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if((nums[i]^nums[i+1])==0) return nums[i];
        }
        return 0;
    }
};
