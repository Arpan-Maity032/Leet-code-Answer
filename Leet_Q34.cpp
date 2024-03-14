/*Find First and Last position in a sorted Array*/

/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>arr;
        int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                if(mid-1<0)
                {
                    arr.push_back(mid);
                    break;
                }
                else if(mid-1>=0 && nums[mid-1]!=target)
                {
                    arr.push_back(mid);
                    break;
                }
                else
                {
                    high=mid-1;
                }
            }

            else if(nums[mid]>target)
            {
                high=mid-1;
            }
            else
            {
                low =mid+1;
            }
        }
        if(arr.empty())
        {
            arr.push_back(-1);
        }

        low=0;
        high=nums.size()-1;

        while(low<=high)
        {
            int mid=low + (high-low)/2;
            if(nums[mid]==target)
            {
                if(mid+1>high)
                {
                    arr.push_back(mid);
                    break;
                }
                else if(mid+1<=high && nums[mid+1]!=target)
                {
                    arr.push_back(mid);
                    break;
                }
                else
                {
                    low=mid+1;
                }
            }
            else if(nums[mid]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        if(arr.size()==1)
        {
            arr.push_back(-1);
        }
        
        return arr;
        
        
    }
};