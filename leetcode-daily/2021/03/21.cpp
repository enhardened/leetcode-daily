// Problem: Reordered Power of 2
// URL: https://leetcode.com/explore/item/3679
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        unordered_map<int, int> digits_in_n;
        int digits_count = 0;
        int n = N;
        
        // Avoid max from overflowing INT_MAX
        if (N == 1000000000)
            return false;
        
        while (n) {
            ++digits_count;
            ++digits_in_n[n % 10];
            
            // cout << n %10 << ":" << digits_in_n[n % 10] << endl;
            
            n = n / 10;
        }
        
        int min = pow(10, digits_count - 1);
        int max = min * 10;
        
        // cout << "[" << min << ".." << max << ")" << endl;
        
        for (int p = 1; p < max; p = p << 1) {
            if (p < min) 
                continue;
            
            if (p == N)
                return true;
            
            if (match(&digits_in_n, p))
                return true;
        }
        
        return false;
    }
    
    bool match(unordered_map<int, int> *digits, int num) {
        unordered_map<int, int> tmp(*digits);
        
        while (num) {
            int digit = num % 10;
            
            if (tmp[digit] == 0)
                return false;
            else
                --tmp[digit];
            
            num = num / 10;
        }
        
        return true;
    }
};