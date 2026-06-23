class Solution {
public:
    int maxArea(vector<int>& height) {
        int mxArea = 0;
        int left = 0;
        int right = height.size() - 1;
        while(left < right){
            mxArea = max(mxArea,min(height[left],height[right]) * (right - left));
            if(height[left] > height[right]){
                right--;
            }else{
                left++;
            }
        }
        return mxArea;
    }
};