class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            vector<int> check(10, 0);
            for(int j = 0; j < 9; j++){
                if(board[i][j] >= '1' and board[i][j] <= '9'){
                    if(check[board[i][j] - '0'] == 1){
                        return false;
                    }
                    check[board[i][j] - '0'] = 1;
                }
            }
        }

        for(int i = 0; i < 9; i++){
            vector<int> check(10, 0);
            for(int j = 0; j < 9; j++){
                if(board[j][i] >= '1' and board[j][i] <= '9'){
                    if(check[board[j][i] - '0'] == 1){
                        return false;
                    }
                    check[board[j][i] - '0'] = 1;
                }
            }
        }

        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                vector<int> check(10, 0);
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++){
                        if(board[i + k][j + l] >= '1' and board[i + k][j + l] <= '9'){
                        if(check[board[i + k][j + l] - '0'] == 1){
                            return false;
                        }
                        check[board[i + k][j + l] - '0'] = 1;
                        }
                    }
                }
            }
        }
        return true;
    }
};
