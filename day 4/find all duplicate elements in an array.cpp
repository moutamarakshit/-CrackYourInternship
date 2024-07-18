class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>vec;
        map<int,int>mpp;
        for(auto it:nums){
        mpp[it]++;
        if(mpp[it]==2)
        vec.push_back(it);
    }
    return vec;
    }
};
