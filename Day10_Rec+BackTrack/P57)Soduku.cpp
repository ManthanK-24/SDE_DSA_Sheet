class Solution {
public:
    bool isValid(int r, int c, vector<vector<char>>&board, char d)
    {
        // check row
        for(int col=0;col<9;col++)
        {
            if(board[r][col]==d)return false;
        }
        // check col
        for(int row=0;row<9;row++)
        {
            if(board[row][c]==d)return false;
        }
        // check 3*3 sub-box
        for(int row=(r/3)*3;row<(r/3+1)*3;row++)
        {
            for(int col=(c/3)*3;col<(c/3+1)*3;col++)
            {
                if(board[row][col]==d)return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
       for(int r=0;r<9;r++)
       {
           for(int c=0;c<9;c++)
           {
               if(board[r][c]=='.')
               {
                   for(char d='1';d<='9';d++)
                   {
                       if(isValid(r,c,board,d))
                       {
                           board[r][c]=d;
                           if(solve(board))return true;
                           board[r][c]='.';
                       }
                   }
                   return false;
               }
           }
       }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
        solve(board);
          
    }
};
