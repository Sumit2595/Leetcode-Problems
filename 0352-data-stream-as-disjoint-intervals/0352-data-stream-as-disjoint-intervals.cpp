class SummaryRanges {
public:
    set<int>st;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<int>stream(st.begin(),st.end());
        vector<vector<int>>ans;
        int start=stream.front();
        int sz=stream.size();
        if(sz==1){
            return {{start,start}};
        }
        int i=1;
        while(i<sz){
            while(i<sz && stream[i-1] + 1 == stream[i]){
                i++;
            }
            if(i==sz){
                break;
            }
            int end=stream[i-1];
            ans.push_back({start,end});
            start=stream[i];
            i++;
        }
        ans.push_back({start,stream[i-1]});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */