class Solution {
public:
    static bool compare(string s,string t){
        int i=0,j=0;
        if(s.length() < t.length())
            return true;
         if(s.length() > t.length())
            return false;
        return s < t;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.rbegin(),nums.rend(),compare);
        return nums[k-1];
    }
};