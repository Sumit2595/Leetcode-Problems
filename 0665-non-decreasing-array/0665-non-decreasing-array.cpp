class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        bool ans=true;
        vector<int>temp=nums;
        for(int i=0;i<n-1;i++){
            if(temp[i] > temp[i+1]){
                temp[i]=temp[i+1];
                break;
            }
        }
        for(int i=0;i<n-1;i++){
            if(temp[i] > temp[i+1]){
                ans=false;
                break;
            }
        }
        for(auto x:temp) cout<<x<<" ";
        if(ans) return true;
        temp=nums;
        cout<<endl;
        for(int i=0;i<n-1;i++){
            if(temp[i] > temp[i+1]){
                temp[i+1]=temp[i];
                break;
            }
        }
        for(auto x:temp) cout<<x<<" ";
        cout<<endl;
        for(int i=0;i<n-1;i++){
            if(temp[i] > temp[i+1]){
                return false;
            }
        }
        return true;
    }
};