class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
     string res;
        vector<string>st;
     int i=0;
        while(i<n)
        {  string temp;
            while(path[i]=='/' && i<n)
              i++;
           while(path[i]!='/'&& i<n)
               temp+=path[i++];
           if(temp==".." && !st.empty())
                st.pop_back();
           if(temp=="."||temp=="")
               continue;
           else if(temp!="..")
              st.push_back(temp); 
        }
      for(auto s:st)
        res+="/"+s;
   return res.empty()?"/":res;
    }
};