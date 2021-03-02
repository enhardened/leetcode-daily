// Problem: https://leetcode.com/problems/set-mismatch
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        /*
        The expected value for nums[i-1] is i for i >= 1 and i <= nums.size()
        So, I can identify which element is wrong by verifying nums[i - 1] != i
        
        Q - Does the error always duplicate the smaller number?
            or it it possible to have [1, 2, 4, 4]?
        A - The custom testcase input accepted [1, 2, 4, 4]. 
            Looks like it's a possible input.
            
        So, after identifying which element is wrong, 
        I need to verify if it is a duplicate of:
        - the previous [1, 2, 3, 3], or 
        - the next element [1, 2, 4, 4]
        and return {i-1, i} for the first case or {i+1, i} on the second.
        */
        vector<int> result(2);
        
        for (int i = 1; i <= nums.size(); ++i) {
            int idx = i - 1;
            
            if (nums[idx] != i)
                if (idx > 0 && nums[idx] == nums[idx - 1])
                    return {i-1, i};
                else
                    return {i+1, i};
        } 
        
        // Shoud never get to this point when the input is valid
        throw invalid_argument("There are no errors on this list");
    }
};