// Problem: Ambiguous Coordinates
// URL: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3741/
class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        vector<string> result;
        
        for (int i = 1; i < s.length() - 2; ++i) {
            string x = s.substr(1, i),
                   y = s.substr(i+1, s.length() -2 -i);
            
            if (x.length() > 1 && x[0] == '0' && x[x.length() - 1] == '0')
                continue;
            
            for (int j = 0; j < x.length(); ++j) {
                
                if (y.length() > 1 && y[0] == '0' && y[y.length() - 1] == '0')
                    continue;
                
                if (x[x.length() - 1] == '0')
                    j = x.length() -1;
                
                for (int k = 0; k < y.length(); ++k) {                    
                    string xf, yf;
                    
                    if (y[y.length() - 1] == '0')
                        k = y.length() -1;  
                    
                    if (j+1 == x.length()) {
                        xf = x;
                    } else {
                        string xi = x.substr(0, j+1),
                               xd = x.substr(j+1, x.length() -j);
                        xf = xi + "." + xd;
                    }
                    
                    if (k+1 == y.length()) {
                        yf = y;
                    } else {
                        string yi = y.substr(0, k+1),
                               yd = y.substr(k+1, y.length() - k);
                        yf = yi + "." + yd;
                    }
                    
                    result.push_back("(" + xf + ", " + yf + ")");
                    
                    if (y.length() > 1 && y[0] == '0')
                        break;
                }
                
                if (x.length() > 1 && x[0] == '0')
                    break;
            }
        }
        
        return result;
    }
};
