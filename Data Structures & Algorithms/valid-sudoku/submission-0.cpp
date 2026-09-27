class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char>boxSet;
        set<char>rowSet;
        set<char>colSet;
        int countB=0, countR=0, countC=0;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                countR = rowSet.size();
                countC = colSet.size();
                if(board[j][i]!= '.') {
                    colSet.insert(board[j][i]);
                    if(countC == colSet.size()) return false;
                }
                if(board[i][j]!= '.') {
                    rowSet.insert(board[i][j]);
                    if(countR == rowSet.size()) return false;
                }
                if(i%3==0 && j%3==0){
                    for(int a=j; a<j+3; a++){
                        for(int b=i; b<i+3; b++){
                            countB = boxSet.size();
                            if(board[a][b]!='.') {
                                boxSet.insert(board[a][b]);
                                if(countB == boxSet.size()) return false;
                            }
                        }
                    }
                    countB=0;
                    boxSet.clear();
                }
            }
            countR=0;
            rowSet.clear();
            countC=0;
            colSet.clear();
        }
        return true;
    }
};
