class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for (char &ch : tasks) {
            freq[ch - 'A']++;
        }
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(freq[i]);
            }
        }
        int interval=0;
        while(!pq.empty()){
            int cycle=n+1;
            int taskCount=0;
            vector<int>store;
            while(cycle-- && !pq.empty()){
                if(pq.top() > 1){
                store.push_back(pq.top()-1);
                }
                pq.pop();
                taskCount++;
            }
            for(auto s:store)
                pq.push(s);
            interval+= pq.empty()?taskCount:n+1;
        }
        return interval;
    }
};