class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int area = 0;
        int i=0;
        int j = size - 1;
        while(i < j){
        int l = min(height[i],height[j]);
        int b = j - i;  
        int carea = b * l;
        area = max(carea,area);
        if(height[i]<height[j]){
            i++;
        }else{
            j--;
        }
    }
    return area;
        
    }
};