class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n=data.size();
        int total_ones=0;
        for(auto d:data){
            if(d == 1)
                total_ones++;
        }
        if(total_ones <= 1)
            return 0;
        int i=0,j=0;
        int ans=n;
        int ones=0,zeros=0;
        while(j<n){
            if(data[j] == 0)
                zeros++;
            if(data[j] == 1)
                ones++;
            while(i<j && j-i+1>=total_ones){
                ans=min(ans,zeros);
                if(data[i] == 0)
                    zeros--;
                if(data[i] == 1)
                    ones--;
                i++;
            }
            j++;
        }
        return ans == n ? 0:ans;
    }
};