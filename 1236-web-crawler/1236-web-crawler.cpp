/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    string getHostName(string url)
    {
        return url.substr(0,url.find('/',7));
    }
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        string hostname=getHostName(startUrl);
        unordered_set<string>st;
        queue<string>q;
        q.push(startUrl);
        while(!q.empty()){
            string t=q.front();
            q.pop();
            st.insert(t);
            for(auto x:htmlParser.getUrls(t))
            {
                string check=getHostName(x);
                if(st.find(x)==st.end() && check==hostname)
                {
                    q.push(x);
                }
            }
        }
        vector<string>ans(st.begin(),st.end());
      return ans;
    }
};