/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int ans=0;
    int solve(Node* root){
        if(!root)
            return 0;
        priority_queue<int>pq;
        int op1=0,op2=0;
        for(auto child:root->children){
            int temp=1+solve(child);
            pq.push(temp);
        }
        if(pq.size()>=2){
            op1=pq.top();pq.pop();
            op2=pq.top();
        } else if(pq.size() == 1){
            op1=pq.top();
        }
        ans=max(ans,op1+op2);
        return op1;
    }
    int diameter(Node* root) {
       solve(root);
       return ans; 
    }
};