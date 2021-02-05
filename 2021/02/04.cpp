/*
Problem: https://leetcode.com/problems/longest-harmonious-subsequence/
Title: Longest Harmonious Subsequence
*/
/*
# Attempt 2:

I can pre-calculate the number of occurrences for every unique number in nums in O(n)
After that, for each unique number, I can check if there are > 0 ocurrences of "number + 1" and "number - 1" also O(n) on the worst case (all numbers in num are unique)
Then, if there are > 0 occurrences, keep the greatest sum of occurrences between (num and num + 1) and (num and num - 1)

For it to work, I'll need a map of unique numbers to number of occurrences and a list of unique numbers - O(n)
Is it possible to extract the list of key from a map? Does not look like there is a standard way.
So I'll probably need a set of numbers - O(n)

Time: O(n)
Space: O(n)

---

# Brute force attempt:

for each number in nums, scan every number after them counting the occurrences of:
    - nums[i] and nums[i] - 1 
    - nums[i] and nums[i] + 1
then, keep the largest number of occurrences
Time: O(n²)
Space: O(1)
*/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> occurrences;
        unordered_set<int> uniqueNumbers;
        
        int n = nums.size(); 
        int result = 0;
        
        for (int i = 0; i < n; ++i) {
            uniqueNumbers.insert(nums[i]);
            ++occurrences[nums[i]];
        }
        
        for (auto num : uniqueNumbers) {
            if (occurrences.count(num + 1) > 0)
                result = max(result, occurrences[num] + occurrences[num + 1]);
            
            if (occurrences.count(num - 1) > 0)
                result = max(result, occurrences[num] + occurrences[num - 1]);
        }
        
        return result;
    }
};