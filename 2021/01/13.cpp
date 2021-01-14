/*
Problem: https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3602/
Title: Boats to Save People
*/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int l = 0;
        int r = people.size() - 1;
        int result = 0;
        
        sort(people.begin(), people.end());
        
        while (l <= r) {
            if (people[r] + people[l] <= limit)
                ++l;
            
            --r;
            ++result;
        }
        
        return result;
    }
};
