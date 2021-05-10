// Problem: https://leetcode.com/explore/item/3670
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {       
        sort(arr.begin(), arr.end());
        
        unordered_map<int, long int> memo;
        memo.reserve(arr.size());
        memo[arr[0]] = 1;
        
        int subject;
        
        long result = memo[arr[0]],
             tmp;
        
        for (int i = 1; i < arr.size(); ++i) {
            memo[arr[i]] = 1;
            
            int right = arr[i] / 2;
            
            for (int j = 0; arr[j] <= right; ++j) {
                if (arr[i] % arr[j] != 0)
                    continue;
                
                subject = arr[i] / arr[j];
                
                if (!memo.count(subject))
                    continue;
                
                tmp = memo[arr[j]] * memo[subject];
                right = subject - 1; // don't need to test again
                
                if (subject != arr[j])
                    tmp *= 2;
                
                memo[arr[i]] += tmp % 1000000007;
            }
            
            result = (result + memo[arr[i]]) % 1000000007;
        }
        
        return result;
    }
};
