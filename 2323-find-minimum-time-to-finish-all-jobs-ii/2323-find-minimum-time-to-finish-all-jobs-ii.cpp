class Solution {
public:
    int minimumTime(vector<int>& jobs, vector<int>& workers) {
        sort(jobs.begin(),jobs.end());
        sort(workers.begin(),workers.end());
        int n=jobs.size();
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            if(jobs[i]<=workers[i]){
              ans=max(ans,1);
            } else {
                int days=jobs[i]/workers[i];
              if(jobs[i] % workers[i])
                  days++;
              ans=max(ans,days);
            }
        }
        return ans;
    }
};