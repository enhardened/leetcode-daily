// Problem: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3655/
class FreqStack {
private:
    int maxFreq = 0;
    unordered_map<int, int> freq;
    unordered_map<int, stack<int, list<int>>> groups;

public:
    FreqStack() {
    }
    
    void push(int x) {
        ++freq[x];
        groups[freq[x]].push(x);
        
        maxFreq = max(maxFreq, freq[x]);
    }
    
    int pop() {
        int num = groups[maxFreq].top();
        
        groups[maxFreq].pop();
        
        if (groups[maxFreq].empty())
            --maxFreq;
        
        --freq[num];
        
        return num;
    }
    
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */