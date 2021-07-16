// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/610/week-3-july-15th-july-21st/3815/
// Title: Valid Triangle Number
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        
        if (n < 3) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        for (auto i = nums.begin(); i != nums.end() - 2; i++) {
            for (auto j = i + 1; j != nums.end() - 1; j++) {
                result += (lower_bound(j+1, nums.end(), (*i) + (*j)) - (j+1));
            }
        }
        
        return result;
    }
};
