深度优先搜索问题

解题思路：

这是一个典型的深度优先搜索问题，在程序处理过程中，将未被'X'包围的‘O’标记为符号‘*’。

先遍历数组边界上的字符‘O’，将其标记为‘*’，然后对出现‘*’的位置，通过递归dfs，遍历其上下左右位置的符号。就这样，由外及内，找出所有未被'X'包围的'O'，且都被标记为了'*'。

最后，再遍历一次board数组，将'*'改为'O'，将'O'改为'X'即可。

 

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if(row == 0) return;
        int col = board[0].size();
        if(col == 0) return;
        //先遍历上下边界中的O
        for(int i = 0; i < col; i++){
            dfs(board, 0, i);
            dfs(board, row-1, i);
        }
        //遍历左右边界中的O
        for(int i = 0; i < row; i++){
            dfs(board, i, 0);
            dfs(board, i, col-1);
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == '*') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        return;        
    }
    void dfs(vector<vector<char> >& board, int i, int j){
        if(i < 0 || i > board.size()-1 || j < 0 || j > board[0].size()-1 || board[i][j] != 'O') return;
        board[i][j] = '*';
        dfs(board, i - 1, j);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i, j + 1);
    }
};