// Problem: https://leetcode.com/explore/item/3674
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int h = -prices[0], // most profit while *h*olding
            z = 0;          // most profit while *z*ero-ed
        
        //cout << h << ", " << z << endl;
        
        for (int i = 1; i < prices.size(); ++i) {
            h = max(h, z-prices[i]);
            z = max(z, h+prices[i]-fee);
            
            //cout << h << ", " << z << endl;
        }
        
        //cout << "---" << endl;
        
        return z;
    }
};
