class Solution {
public:
    int findLHS(vector<int>& nums) {
        // First trying a brute force method
        /*
        for each number in nums, scan every number after them counting the occurrences of:
            - nums[i] and nums[i] - 1 
            - nums[i] and nums[i] + 1
        then, keep the largest number of occurrences
        Time: O(n²)
        Space: O(1)
        */
        int n = nums.size(); 
        int result = 0;
        
        for (int i = 0; i < n; ++i) {
            int countEqual = 1,
                countPlusOne = 0,
                countMinusOne = 0;
            
            for (int j = i+1; j < n; ++j)
                if (nums[j] == nums[i]) 
                    ++countEqual;
                else if (nums[j] == nums[i] + 1)
                    ++countPlusOne;
                else if (nums[j] == nums[i] - 1)
                    ++countMinusOne;
            
            // If all numbers are equal, the difference between min and max is 0
            if (countPlusOne > 0 || countMinusOne > 0)
                result = max(result, max(countEqual + countPlusOne, countEqual + countMinusOne));
        }
        
        return result;
    }
};