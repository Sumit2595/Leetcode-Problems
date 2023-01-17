class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int low=0,high=n-1;
        int area=0;
        while(low<high){
            int b=high-low;
            int l=min(height[low],height[high]);
            area=max(area,l*b);
            if(l==height[low]){
                low++;
            } else{
                high--;
            }
        }
        return area;
    }
};