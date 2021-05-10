// Problem: https://leetcode.com/explore/item/3673
class Solution {
public:
    string c = "aaaaaa";
    unordered_map<string, string> urlMap;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        urlMap[c] = longUrl;
        string tmp = c;
            
        for (int i = 0; i < 6; ++i) {
            int x = 6-i;
            
            if ((c[x] >= 'a' && c[x] < 'z') || (c[x] >= 'A' && c[x] < 'Z') || (c[x] >= '0' && c[x] < '9'))
                c[x] += 1;
            else if (c[x] == 'z')
                c[x] = 'A';
            else if (c[x] == 'Z')
                c[x] = '0';
            else {
                c[x] = 'a';
                continue;
            }
            
            break;
        } 
        
        return "http://tinyurl.com/" + tmp;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return urlMap[shortUrl.substr(19, 6)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));