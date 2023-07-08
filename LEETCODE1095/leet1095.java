/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */
 
class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int start = 0;
        int end = mountainArr.length() - 1;

        //finding the peak
        while (start < end){
            int mid = start + (end - start) / 2; 
            if (mountainArr.get(mid) > mountainArr.get(mid + 1)){
                end = mid;
            }
            else{
                start = mid + 1;
            }
        }
        int peak = start;

	//finding the target in the first part of the array
        start = 0;
        end = peak; 
        while (start <= end){
            int mid = start +(end - start) / 2;
            if (mountainArr.get(mid) == target){
                return mid;
            }else if(mountainArr.get(mid) < target){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }

	//finding the target in the second part of the array
        start = peak;
        end = mountainArr.length() - 1;
        while (start <= end){
            int mid = start +(end - start) / 2;
            if (mountainArr.get(mid) == target){
                return mid;
            }else if(mountainArr.get(mid) < target){
                end = mid - 1;
               
            }else{
                start = mid + 1;
            }
        }
        
        return -1;

    }
}
