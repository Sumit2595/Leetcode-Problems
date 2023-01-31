class Solution
{
    public:
        #define pp pair<int, int>
        int bestTeamScore(vector<int> &scores, vector<int> &ages)
        {
            int n = scores.size();
            vector<pp> vec;
            for (int i = 0; i < n; i++)
            {
                vec.push_back({ scores[i],
                    ages[i] });
            }
            sort(vec.begin(), vec.end());
            vector<int> dp(n, 0);
            int ans = 0;
            for (int i = 0; i < vec.size(); i++)
            {
                dp[i] = vec[i].first;
                for (int j = 0; j < i; j++)
                {
                    if (vec[j].second <= vec[i].second)
                    {
                        dp[i] = max(dp[i], dp[j] + vec[i].first);
                    }
                }
                ans = max(ans, dp[i]);
            }
            return ans;
        }
};