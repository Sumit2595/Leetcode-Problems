class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(nums[0] == nums[n-1]){
            return 0;
        }
        int small=nums[0];
        int numberInBetween=0;
        int currLargest=nums[n-1];
        cout<<currLargest<<" ";
        int i=n-1;
        while(currLargest!=small){
            cout<<currLargest<<" ";
            if(currLargest==nums[i]){
                i--;
                continue;  
            }
            numberInBetween++;
            currLargest=nums[i];
            i--;
        }
        int operations=0;
        i=n-1;
        currLargest=nums[n-1];
        while(currLargest!=small){
            if(currLargest==nums[i]){
                operations+=numberInBetween;
                i--;
                continue;  
            }
            numberInBetween--;
            operations+=numberInBetween;
            currLargest=nums[i];
            i--;
        }
        return operations;
    }
};