class Solution
{
    public:
        unordered_map<string, bool> memo;
    int n;

    bool nimGame(vector<int> &piles)
    {
        n = piles.size();
        return dp(piles, n);
    }

    string getKey(vector<int> &piles)
    {
        string ans = "";
        for (auto p: piles)
            ans += to_string(p);
        return ans;
    }

    bool dp(vector<int> piles, int remain)
    {
        if (remain == 1)
            return true;
        sort(piles.begin(), piles.end());
        string key = getKey(piles);
        if (!memo.count(key))
        {
            memo[key] = false;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 1; j <= piles[i]; ++j)
                {
                    piles[i] -= j;
                    if (!dp(piles, piles[i] == 0 ? remain - 1 : remain))
                        memo[key] = true;
                    piles[i] += j;
                }
            }
        }
        return memo[key];
    }
};