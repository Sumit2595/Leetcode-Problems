class Solution {
public:
    #define ll long long
    int bsearch(vector<int>& potions,int num,ll success){
        int low=0,high=potions.size();
        while(low<high){
            int mid=low+(high-low)/2;
            ll prod=(ll)potions[mid]*num;
            if(prod>=success){
                high=mid;
            } else{
                low=mid+1;
            }
        }
        return potions.size()-low;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=spells.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int pairs=bsearch(potions,spells[i],success);
            ans.push_back(pairs);
        }
        return ans;
    }
};