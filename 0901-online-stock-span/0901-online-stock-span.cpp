class StockSpanner {
public:
    #define pp pair<int,int>
    stack<pp>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.empty()){
            st.push({price,1});
            return 1;
        } else {
            int span=1;
            if(st.top().first>price){
                st.push({price,1});
            } else {
                while(!st.empty() && st.top().first<= price){
                    span+=st.top().second;
                    st.pop();
                }
                st.push({price,span});
            }
            return span;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */