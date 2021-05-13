// Problem: Range Sum Query - Immutable
// URL: https://leetcode.com/problems/range-sum-query-immutable/
class NumArray {
public:
    vector<int> memo;
    
    NumArray(vector<int>& nums) {
        int n = nums.size() + 1;
        
        this->memo.resize(n);
        this->memo[0] = 0;
            
        for (int i = 1, p = 0; i < n; ++i, ++p) {
            this->memo[i] = this->memo[p] + nums[p];
        }
    }
    
    int sumRange(int left, int right) {
        return memo[right + 1] - memo[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */