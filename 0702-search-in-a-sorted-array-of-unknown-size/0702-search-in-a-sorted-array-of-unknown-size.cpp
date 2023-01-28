/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
       int index=-1,high=1;
       while(1){
           int low=0;
           high=2 * (high);
           while(low <= high) {
               int mid=high+(low-high)/2;
               int val= reader.get(mid);
               if(val == target){
                   return mid;
               } else if(val<target){
                   low=mid+1;
               } else {
                   high=mid-1;
               }
           }
           if(reader.get(low) > target){
               break;
           }
       }
        return index;
    }
};