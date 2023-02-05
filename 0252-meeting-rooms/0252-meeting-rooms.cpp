class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& nums) {
        int n=nums.size();
        if(n==0){
            return true;
        }
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(nums[i-1][1]>nums[i][0]){
                return false;
            }
        }
        return true;
    }
};