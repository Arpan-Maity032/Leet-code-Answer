/*Longest Valid Parentheses*/

/*Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
substring
.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0*/


class Solution {
public:
    int longestValidParentheses(string s) {
        stack <int> st ;
        st.push(-1) ;

        int length = 0 ;

        for (int i = 0 ; i<s.length() ; i++) {

            if (s[i] == '(')
                st.push(i) ;
            
            else
                st.pop() ;
                if (!st.empty()) {
                    int len = i - st.top() ;
                    length = max(length , len) ;
                }
                else
                    st.push(i) ;
        }
        return length ;         
    }
};