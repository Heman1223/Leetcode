class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int i = 0;
        int j = height.size() - 1;
        while(i < j){
            int area = min(height[i],height[j]) * (j - i);
            ans = max(area,ans);
            if(height[i] > height[j]){
                j--;
            }else{
                i++;
            }
        }
        return ans;
    }
};