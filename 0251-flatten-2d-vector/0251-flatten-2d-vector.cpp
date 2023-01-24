class Vector2D {
public:
    int index=0;
    vector<int>flatten;
    Vector2D(vector<vector<int>>& vec) {
        for(auto x:vec){
            for(auto y:x){
                flatten.push_back(y);
            }
        }
    }
    
    int next() {
        int ans=flatten[index];
        index++;
        return ans;
    }
    
    bool hasNext() {
        if(index<flatten.size())
            return true;
        return false;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */