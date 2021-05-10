// Problem: https://leetcode.com/explore/item/3675
class Solution {
public:
    double cx,
           cy,
           r,
           pi = 2 * acos(0.0);
    
    Solution(double radius, double x_center, double y_center) {
        cx = x_center;
        cy = y_center;
        
        r = radius;
    }
    
    double randDouble() {
        return ((double) rand() / RAND_MAX);
    } 
    
    vector<double> randPoint() {
        double t = randDouble() * 2 * pi;
        double d = sqrt(randDouble()) * r;
        
        return {cx + d * cos(t), cy + d * sin(t)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
