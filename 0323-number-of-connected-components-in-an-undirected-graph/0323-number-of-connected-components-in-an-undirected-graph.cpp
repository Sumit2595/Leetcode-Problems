class Solution {
    
     class UnionFind{
         vector<int> roots;
         vector<int> rank;
         public:
         UnionFind(int n){
             roots.resize(n);
             rank.resize(n, 0);
             for(int i=0; i < n; ++i){
                 roots[i] = i;
             }
         };
         
         int find(int k){
             
             if(roots[k] == k)
                 return k;
             
             return roots[k] = find(roots[k]); //path compression
         }
         
         bool Union(int a, int b){
             
             int rootsa = find(a);
             int rootsb = find(b);
             
             if(rootsa == rootsb)
                 return false;
             
             if(rank[rootsa] > rank[rootsb])
                 roots[rootsb] = rootsa;
             else if(rank[rootsa] < rank[rootsb])
                 roots[rootsa] = rootsb;
             else{
                 roots[rootsb] = rootsa;
                 rank[rootsa] += 1;
             }
             
             return true;
         }
         
         
         
     };
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        //Use Union find algo to connect components. Maintain counter for number of nodes and reduce with each
        //union. Remaning count is the result - num of components
        
        int count = n;
        UnionFind uf(n);
        for(auto e : edges){
            if(uf.Union(e[0], e[1]))
                count -= 1;
            
        }
        
        return count;
    }
};