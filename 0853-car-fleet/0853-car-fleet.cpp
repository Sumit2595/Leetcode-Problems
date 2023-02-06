class Solution {
public:
    #define pp pair<int,int>
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pp>vec;
        int n=position.size();
        for(int i=0;i<n;i++){
            vec.push_back({position[i],speed[i]});
        }
        sort(vec.begin(),vec.end());
        stack<double>st;
        int d=vec[n-1].first;
        int s=vec[n-1].second;
        double time=(target-d)/(double)s;
        st.push(time);
        int pos=vec[0].first;
        for(int i=n-2;i>=0;i--){
            d=vec[i].first;
            s=vec[i].second;
            time=(target-d)/(double)s;
            if(st.top() < time){   
                st.push(time);
            } 
        }
        return st.size();
    }
};