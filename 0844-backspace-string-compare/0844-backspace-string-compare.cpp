class Solution {
public:
    bool isSameStack(stack<char> stack1, stack<char> stack2)
    {
        bool flag = true;

        if (stack1.size() != stack2.size()) {
            flag = false;
            return flag;
        }

        while (stack1.empty() == false) {
            if (stack1.top() == stack2.top()) {
                // Pop top of both stacks
                stack1.pop();
                stack2.pop();
            }
            else {
                flag = false;
                break;
            }
        }
        return flag;
    }
    bool backspaceCompare(string s, string t) {
       stack<char>st1;
       stack<char>st2;
       for(auto x:s){
           if(x == '#'){
               if(!st1.empty())
                st1.pop();
               continue;
           }
           st1.push(x);
       }
       for(auto x:t){
           if(x == '#'){
               if(!st2.empty())
                st2.pop();
               continue;
           }
           st2.push(x);
       } 
        return isSameStack(st1,st2);
    }
};