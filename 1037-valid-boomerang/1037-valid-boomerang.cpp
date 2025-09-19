class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
    // Step 1: all three points must be distinct
    if (points[0] == points[1] || points[1] == points[2] || points[0] == points[2]) {
        return false;
    }

    // Step 2: check collinearity using area of triangle formula
    int x1 = points[0][0], y1 = points[0][1];
    int x2 = points[1][0], y2 = points[1][1];
    int x3 = points[2][0], y3 = points[2][1];

    // Calculate determinant (shoelace formula)
    return (x2 - x1) * (y3 - y1) != (y2 - y1) * (x3 - x1);
}

};