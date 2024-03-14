'''
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
'''

class Solution:
    def trap(self, height: List[int]) -> int:
        r=len(height)-1
        l=0
        ans=0
        lmax=-1
        rmax=-1
        while(r>l):
            lmax=max(lmax,height[l])
            rmax=max(rmax,height[r])
            if lmax<rmax:
                ans +=lmax-height[l]
                l=l+1
            else:
                ans +=rmax-height[r]
                r=r-1

        return ans