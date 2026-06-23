class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> rightH(n);
        vector<int> leftH(n);

        leftH[0] = height[0];
        for(int i = 1;i < n;i++){
            leftH[i] = max(leftH[i - 1],height[i]);
        }
        
        rightH[n - 1] = height[n - 1];
        for(int i = n - 2;i >= 0;i--){
            rightH[i] = max(rightH[i + 1],height[i]);
        }

        int totalWater = 0;
        for(int i = 0;i < n;i++){
            totalWater += min(leftH[i],rightH[i]) - height[i];
        }
        return totalWater;
    }
};