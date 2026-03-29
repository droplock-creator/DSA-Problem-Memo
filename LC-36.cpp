// Link to question: https://leetcode.com/problems/valid-sudoku/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++){
            vector<int> hashR(9,0);
            for (int j = 0; j < 9; j++){
                if (board[i][j] != '.'){
                    hashR[board[i][j]-'1']++;
                    if(hashR[board[i][j]-'1']==2) {return false;}
                }
            }
        }
         for (int i = 0; i < 9; i++){
            vector<int> hashC(9,0);
            for (int j = 0; j < 9; j++){
                if (board[j][i] != '.'){
                    hashC[board[j][i]-'1']++;
                    if(hashC[board[j][i]-'1']==2) {return false;}
                }
            }
        }
        for (int i = 0; i < 9; i++){
            vector<int>hashG(9,0);
            int j = (i/3)*3;
            for (int r = j; r < j+3; r++){
                int k = (i%3)*3;
                for (int c = k; c < k+3; c++ ){
                    if (board[r][c] != '.') {
                        hashG[board[r][c]-'1']++;
                        if (hashG[board[r][c]-'1'] == 2){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};