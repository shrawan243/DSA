class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        
        while (left < right) {
            // Move left pointer past non-alphanumeric characters
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // Move right pointer past non-alphanumeric characters (THIS WAS MISSING)
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            // Compare characters after converting to lowercase
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
};