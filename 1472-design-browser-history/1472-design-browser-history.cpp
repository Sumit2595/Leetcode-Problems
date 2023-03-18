class BrowserHistory {
public:
    vector<string>history;
    int curr=0;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
    }
    
    void visit(string url) {
        history.erase(history.begin()+curr+1,history.end());
        history.push_back(url);
        curr++;
    }
    
    string back(int steps) {
        if(steps<=curr){
            curr-=steps;
            return history[curr];
        }
        curr=0;
        return history[0];
    }
    
    string forward(int steps) {
        int rem=history.size()-curr-1;
        if(steps<=rem){
            curr+=steps;
            return history[curr];
        }
        curr=history.size()-1;
        return history[history.size()-1];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */