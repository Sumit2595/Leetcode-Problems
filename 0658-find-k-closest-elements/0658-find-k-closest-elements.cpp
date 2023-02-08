class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int low=0,high=n-1;
        vector<int>ans;
        int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(arr[mid] == x){
                break;
            } else if(arr[mid] > x) {
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        
        if(mid ==0){
            low=mid;
            high=mid+1;
        } else {
            low=mid-1;
            high=mid;  
        }
        while(low>=0 && high<n && k){
            if(abs(arr[low]-x)<=abs(arr[high]-x)){
                ans.push_back(arr[low]);
                low--; 
            } else {
               ans.push_back(arr[high]); 
                high++;
            }
            k--;
        }
        while(k && low>=0){
            ans.push_back(arr[low]);
            low--;
            k--;
        }
        while(k && high<n){
            ans.push_back(arr[high]);
            high++;
            k--;
        }
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};