class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = nums[0];
        int max_so_far=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            current_sum=max(nums[i],current_sum+nums[i]);
            max_so_far =max(max_so_far,current_sum);
        }
    return max_so_far;
        
    }
};