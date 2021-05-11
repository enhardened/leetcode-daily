// Problem: Count Primes
// URL: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3738/
class Solution {
public:
    int countPrimes(int n) {
        if (n < 3)
            return 0;
        
        bitset<5000000> nonprimes;
        nonprimes.set(0);
        nonprimes.set(1);
        
        for (int i = 2, I = sqrt(n) + 1; i < I; i++)
            if (!nonprimes.test(i))
                for (int j = i*i; j < n; j += i)
                    nonprimes.set(j);
        
        return n - nonprimes.count();
    }
};
