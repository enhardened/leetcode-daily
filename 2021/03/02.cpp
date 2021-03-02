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
        
        ---
        
        Looks like the list is not always sorted. So, I can:
        - sort the list, the space complexity would still be constant but time would be n*log(n)
        - create an unordered_set from nums while searching for the duplicate in linear time
          but increasing the space complexity to linear ()
        - use a bitset instead of the unordered_set from the previous option, maintaining the linear time
          but with constant worse-case space (10^4bits vs [2*32, (10^4)*32]bits)
          
        ---
        
        Looks like any number on the set could have been overwriten, 
        not only the next or previous of the duplicated.
        So, the sorting option is not really an option.
        
        I'll go first with the map option, which seens more straight forward and try bitset after.
        */
        int n = nums.size();
        bitset<10000> mask;
        mask.flip();
        vector<int> result(2);
        
        for (auto num : nums) {
            int idx = num - 1;
            
            if (!mask.test(idx))
                result[0] = num;
            
            mask.reset(idx);
        }
        
        cout << mask << endl;
        
        for (int i = 0; i < n; ++i) {
            if (mask.test(i)) {
                result[1] = i+1;
                break;
            }
        }
        
        return result;
    }
};
