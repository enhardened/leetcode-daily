// Problem: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3655/
class FreqStack {
public:
    unordered_map<int, int> frequences;
    vector<int> nums;
    
    FreqStack() {
        
    }
    
    void push(int x) {
        ++frequences[x];
        nums.push_back(x);
    }
    
    int pop() {
        int popped;
        int highest_freq = 0;
        vector<int> most_freq_nums;
        
        for (auto frequency : frequences)
            highest_freq = max(highest_freq, frequency.second);
        
        for (auto frequency : frequences)
            if (highest_freq == frequency.second)
                most_freq_nums.push_back(frequency.first);
        
        bool found = false;
        
        for (int i = nums.size() - 1; i >= 0; --i) {
            for (int j = 0; j < most_freq_nums.size(); ++j) {
               if (most_freq_nums[j] == nums[i]) {
                   popped = nums[i];
                   nums.erase(nums.begin() + i);
                   found = true;
                   break;
               } 
            }
            
            if (found)
                break;
        }
        
        --frequences[popped];
        
        return popped;
    }
    
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */