/*SEARCH INSERT POSITION*/

/*Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int s = 0,e = nums.size()-1,mid = 0;

        while(s <= e){
            mid = s + (e-s)/2;

            if(nums[mid]==target)
                return mid;
            else if(nums[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;

        }

        if(target > nums[mid])
            return mid + 1;
        else
            return mid;
    
    }
};