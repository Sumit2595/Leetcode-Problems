class Solution {
public:
    int countOdds(int low, int high) {
        int count=0;
        int totalNumber=high-low+1;
        if(totalNumber%2==0){
            count+=(totalNumber/2);
        } else {
            if(low % 2){
                count+=(totalNumber/2)+1;
            } else {
                count+=(totalNumber/2);
            }
        }
        return count;
    }
};