#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Ensure nums1 is the smaller array to optimize binary search range
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;
        int halfLen = (m + n + 1) / 2;
        
        while (low <= high) {
            int i = (low + high) / 2;
            int j = halfLen - i;
            
            int nums1LeftMax = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1RightMin = (i == m) ? INT_MAX : nums1[i];
            
            int nums2LeftMax = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2RightMin = (j == n) ? INT_MAX : nums2[j];
            
            // Check if we have partitioned both arrays correctly
            if (nums1LeftMax <= nums2RightMin && nums2LeftMax <= nums1RightMin) {
                // If total number of elements is odd, median is the max of left elements
                if ((m + n) % 2 != 0) {
                    return std::max(nums1LeftMax, nums2LeftMax);
                }
                // If total number of elements is even, median is the average of left-max and right-min
                return (std::max(nums1LeftMax, nums2LeftMax) + std::min(nums1RightMin, nums2RightMin)) / 2.0;
            } 
            else if (nums1LeftMax > nums2RightMin) {
                // Too many elements from nums1 in the left partition; move search range left
                high = i - 1;
            } 
            else {
                // Too few elements from nums1 in the left partition; move search range right
                low = i + 1;
            }
        }
        
        return 0.0;
    }
};