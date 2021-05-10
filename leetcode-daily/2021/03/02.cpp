// Problem: https://leetcode.com/problems/set-mismatch
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        /*
        Trying to implement linear time and constant space solution re-using the nums vector.
        */
        vector<int> result(2);
        
        for (auto num : nums) {
            int abs_num = abs(num);
            int abs_idx = abs_num - 1;
            
            if (nums[abs_idx] < 0)
                result[0] = abs_num;
            else
                nums[abs_idx] *= -1;
        }
            
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] > 0) {
                result[1] = i + 1;
                break;
            }
        
        return result;
    }
};