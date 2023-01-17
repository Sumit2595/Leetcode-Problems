class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            int sum=nums[i];
            int l=i+1,r=n-1;
            while(l<r){
                int target=nums[l]+nums[r];
                if(target+sum<0){
                    l++;
                } else if(target+sum>0) {
                    r--;
                } else{
                    vector<int>triplet={nums[i],nums[l],nums[r]};
                    ans.push_back(triplet);
                    while(l<r && nums[l]==triplet[1])
                    l++;
                    while(l<r && nums[r]==triplet[2])
                    r--;
                }
            }
           while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
            i++;
        }
        return ans;
    }
};