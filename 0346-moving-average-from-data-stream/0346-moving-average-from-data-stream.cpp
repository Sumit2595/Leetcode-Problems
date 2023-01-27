class MovingAverage {
public:
    int sum=0;
    deque<int>dq;
    int sz;
    MovingAverage(int size) {
        sz=size;
    }
    
    double next(int val) {
        dq.push_back(val);
        sum+=val;
        if(dq.size()<=sz){
        } else{
            int first=dq.front();
            dq.pop_front();
            sum-=first;
        }
        return sum/(double)dq.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */