class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        if(n==1){
            return {-1};
        }
        vector<int>maxFromRight(n);
        maxFromRight[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            maxFromRight[i]=max(arr[i],maxFromRight[i+1]);
        }
        arr[n-1]=-1;
        for(int i=0;i<n-1;i++){
            arr[i]=maxFromRight[i+1];
        }
        return arr;
    }
};