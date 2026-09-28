class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       int l=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<l-1;i++)
        {
            int p=nums[i];
            int q=nums[i+1];
            if(p==q)
            {
                return true;
            }
        }
        return false;
        
    }
};