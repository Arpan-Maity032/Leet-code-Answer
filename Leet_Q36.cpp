/*VALID SUDOKO*/

/*Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:


Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left*/



class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
           //Three Cases so 3 condtions.
        int rowcase[9][9] ={0};
        int colcase[9][9] = {0};
        int gridcase[9][9] = {0};

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
//                 if it is number.
                if(board[i][j] != '.'){
                    int number = board[i][j] - '0';


                    int k = i/3*3  + j/3 ;
                    // k denotes grid number

                    // check for the 3 case.
     if(rowcase[i][number-1]++ || colcase[j][number-1]++ || gridcase[k][number-1]++)
                        return false;

                }
            }
        }
        return true;

    }
};