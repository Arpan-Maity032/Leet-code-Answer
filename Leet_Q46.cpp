/*PERMUTATION*/

/*Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]*/

class Solution {
public:
    void backtracting(vector<int>& nums,vector<vector<int>>& ans,int start)
    {
        int z=nums.size();
        if(start==z)
        {
            ans.push_back(nums);

        }
        else{
            for(int i=start;i<z;i++)
            {
                swap(nums[i],nums[start]);
                backtracting(nums,ans,start+1);
                swap(nums[i],nums[start]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;

        backtracting(nums,ans,0);
        return ans;
    }
};