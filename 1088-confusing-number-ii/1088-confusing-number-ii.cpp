class Solution {
    int count;

    long long getDigits(long long num)
    {
        static int map[] = { 0, 1, -1, -1, -1, -1, 9, -1, 8, 6 };
        long long res = 0;
        while (num)
        {
            int d = num % 10;
            res *= 10;
            res += map[d];
            num /= 10;
        }
        return res;
    }

    void gen(vector<int> v, long long num, int N)
    {
        if (num > N) return;
        for (int i : v)
        {
            long long temp = num * 10 + i;
            if (temp <= N)
            {
                long long res = getDigits(temp);
                if (res != temp)
                {
                    count++;
                }
                gen(v, temp, N);
            }
        }
    }

public:
    int confusingNumberII(int N) {
        count = 2;
        vector<int> v = { 0, 1, 6, 8, 9 };
        for (int i = 1; i < v.size(); i++)
        {
            gen(v, v[i], N);
        }
        return count;
    }
};