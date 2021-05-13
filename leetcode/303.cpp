// Problem: Range Sum Query - Immutable
// URL: https://leetcode.com/problems/range-sum-query-immutable/
class NumArray {
public:
    vector<int> memo;
    
    NumArray(vector<int>& nums) {
        this->memo.resize(nums.size());
        this->memo[0] = nums[0];
            
        for (int i = 1; i < nums.size(); ++i) {
            this->memo[i] = this->memo[i-1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) {
            return memo[right];
        }
        
        return memo[right] - memo[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */