/*
wildcard pattern matching

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
*/

class Solution {
public:
    bool isMatch(string s, string p) {
       int n = s.length();
        int m = p.length();
        bool dp[n+1][m+1];
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            dp[i][0] = 0;
        }
        for(int i = 1; i <= m; i++){
            dp[0][i] = 0;
        }
        int ind = 1;
        while(ind <= m){
            if(p[ind-1] != '*') break;
            dp[0][ind] = 1;
            ind++;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else if(s[i-1] == p[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return dp[n][m];
    }
};
