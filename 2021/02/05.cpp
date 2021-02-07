/*
Problem: https://leetcode.com/problems/simplify-path/
Title: Simplify Path
*/
class Solution {
public:
    string dirListToString(vector<string> *dirList) {
        if (dirList->size() == 0) 
            return "/";
        
        string path = "";
        
        for (auto dir : *dirList)
            path += "/" + dir;
        
        return path;
    }
    
    string simplifyPath(string path) {
        vector<string> dirList;
        string dir = "";
        
        if (path[path.size() -1] != '/')
            path += "/";
        
        for (auto c : path) {
            if (c == '/') {
                if (dir == "..") {
                    if (dirList.size() > 0)
                        dirList.pop_back();
                } else if (dir != "." && dir != "") {
                    dirList.push_back(dir);
                }
                
                dir = "";
            } else {
                dir += c;   
            }
        }
        
        return dirListToString(&dirList);
    }
};
