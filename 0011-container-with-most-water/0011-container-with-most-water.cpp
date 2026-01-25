class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int right = n - 1;
        int left = 0;
        int maxarea = INT_MIN;
        while(left < right){
            maxarea = max(maxarea, (min(height[left],height[right]) * (right - left)));
            if(height[left + 1] > height[left]){
                left++;
            }else if(height[right - 1] > height[right]){
                right--;
            }else{
                left++;
                right--;
            }

        }
        return maxarea;
    }
};