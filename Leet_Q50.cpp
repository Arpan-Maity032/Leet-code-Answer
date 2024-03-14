/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).


Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/

class Solution {
public:
    double myPow(double x, int n) {

        if(n==0 || x==1)
         return 1;
        if(x==0)
            return 0;

        double val= myPow(x,n/2);
        val*=val;

        if(n%2==0)
         return val;

        else{

            if(n<0)
             return (1/x*val);

            return val*x;
        }
    }
};