#define ll long long
#define pii pair<int,int>
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        priority_queue<pii,vector<pii>,greater<pii>>minHeap;
        priority_queue<pii>maxHeap;
        int left=0,right=0;
        minHeap.push({nums[0],0});
        maxHeap.push({nums[0],0});
        ll count=0;
        while(right<n){
            minHeap.push({nums[right],right});
            maxHeap.push({nums[right],right});
            while(left<right && (maxHeap.top().first - minHeap.top().first > 2)){  
                left++;
                while(!minHeap.empty() && minHeap.top().second < left){
                    minHeap.pop();
                }
                 while(!maxHeap.empty() && maxHeap.top().second < left){
                    maxHeap.pop();
                }
                
            }
            count+=(right-left+1);
            right++;
        }
        return count;
    }
};