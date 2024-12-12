#define ll long long
class Solution {
public:
    ll getSqrt(int num){
        ll i=1;
        for(;i*i<=num;i++){
            if(i*i == num)
                return i;
        }
        return i-1;
    }
    long long pickGifts(vector<int>& gifts, int k) {
        int n=gifts.size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            pq.push(gifts[i]);
        }
        ll sum=0;
        while(!pq.empty() && k--){
            int top=pq.top();pq.pop();
            cout<<getSqrt(top)<<" ";
            pq.push(getSqrt(top));
        }
        while(!pq.empty()){
            sum+=pq.top();pq.pop();
        }
        return sum;
    }
};