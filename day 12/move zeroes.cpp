class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
       /* for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(nums[j]==0)
                    swap(nums[j],nums[j+1]);
        }
    }
    */
    int lastnonzeroelement=0;
    for(int i=0;i<n;i++){
        if(nums[i]!=0){
            nums[lastnonzeroelement]=nums[i];
            lastnonzeroelement++;
        }
    }
    for(int i=lastnonzeroelement;i<n;i++)
        nums[i]=0;
    }
};
