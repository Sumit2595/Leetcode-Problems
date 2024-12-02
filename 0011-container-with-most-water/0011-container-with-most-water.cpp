class Solution {
public:
    int maxArea(vector<int>& height) {
       int start=0,end=height.size()-1;
        int maxArea=0;
        while(start<=end){
            int h=min(height[start],height[end]);
            int w=end-start;
            int area=h * w;
            maxArea=max(maxArea,area);
            if(height[start] <= height[end]){
                start++;
            } else {
                end--;
            }
        }
        return maxArea;
    }
};