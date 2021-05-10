// Problem: 
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        // Do I need to keep the same order?
        // Looks like I don't.
        
        // So, to find the shortest string, I need to verify if
        // there are strings that match the end of order strings
        // Ex.: "me" matches the end of "time"
        //      but "me" does not match the end of "timee"
        
        // I guess I'll need to find shorter words with match
        // the end of longer words, keeping track of their index on which they
        // match the longer word.
        // It would also apply for identical words 
        // (which would be of the same length, not necessarily shorter)
        
        // I believe I could sort the vector by word length
        // them iterate over each word verifying if they match any of the next words
        // - if id doesn't, add the word to the result string
        // - if it does, add the matching word length minus the current word length to a map
        // which the key is the matching word and the value is a list with the subtraction result
        // added to it
        // after the last iteration, I'd iteract over every key of the map 
        // -----
        // As I don't need to build the string, only return its length
        // I can simply ignore strings that match the end of others
        // and add the length of the ones that doesn't + 1 to the result
        // now, if I sort the words list, I'll have O(n*log(n) + (n^2)/2) 
        // vs O(n^2) time complexity 
        
        // Looks like quadratic time is not enougth (First try timed out)
        // Maybe, I can sort the array by the alphabetic order of the reversed string
        // This way, I'll just need to compare a string with the next one
        // reducing time complexity to O(n*log(n) + n). 
        // (ignoring the complexity of "compare()" as string length is, at most, 7)
        
        int n = words.size(),
            result = 0;
        
        sort(words.begin(), words.end(), [](auto a, auto b) { 
            int ia = a.length() - 1;
            int ib = b.length() - 1;
            
            while (ia >= 0 && ib >= 0) {
                if (a[ia] == b[ib]) {
                    --ia;
                    --ib;
                    continue;
                }
                
                return a[ia] < b[ib];
            }
            
            return ia < ib;
        });
        
        for (int i = 0; i < n - 1; ++i)
            if (!compare(words[i], words[i+1]))
                result += words[i].length() + 1;
        
        result += words[n-1].length() + 1;
        
        return result;
    }
    
    bool compare(string a, string b) {
        if (a.length() > b.length())
            a.swap(b);
        
        int diff = b.length() - a.length();
        
        for (int i = 0; i < a.length() && i < b.length(); ++i)
            if (b[diff + i] != a[i])
                return false;
        
        return true;
    }
};