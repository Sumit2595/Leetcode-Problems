class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int>v1,v2,v3;
        int end=n-k;
        for(int i=0;i<end;i++){
            v1.push_back(nums[i]);
        }
        for(int i=end;i<n;i++){
            v2.push_back(nums[i]);
        }
        v2.insert(v2.end(),v1.begin(),v1.end());
        for(int i=0;i<n;i++){
            nums[i]=v2[i];
        }
    }
};