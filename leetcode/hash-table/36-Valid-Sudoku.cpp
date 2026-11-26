class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //rows
        for(int i=0;i<9;i++){
            set<char> s;
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                if(s.count(board[i][j])){
                    return false;
                }
                s.insert(board[i][j]);
            }
        }
        //columns
        for(int j=0;j<9;j++){
            set<char> s;
            for(int i=0;i<9;i++){
                if(board[i][j]=='.'){
                    continue;
                }
                if(s.count(board[i][j])){
                    return false;
                }
                   s.insert(board[i][j]);
            }
        }
        //3*3
        for(int row=0;row<9;row+=3){
              for(int column=0;column<9;column+=3){
                set<char> s;
                for(int i=row;i<row+3;i++){
                    for(int j=column;j<column+3;j++){
                        if(board[i][j]=='.'){
                          continue;
                        }
                        if(s.count(board[i][j])){
                            return false;
                        }
                        s.insert(board[i][j]);
                    }
                }
              }
        }
        return true;
    }
};