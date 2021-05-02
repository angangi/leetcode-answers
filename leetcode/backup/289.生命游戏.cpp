/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

// @lc code=start
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> board2(board);
        int dimOut = board.size();
        if(board.size() < 1) return;
        int dimIn = board[0].size();
        for(int i=0;i<dimOut;++i){
            for(int j=0;j<dimIn;++j){
                int cnt = checkCountOfNeighborLiveCell(board, i, j, dimOut, dimIn);
                if(board[i][j] == 0) {
                    if(cnt == 3) {
                        board2[i][j] = 1;
                    }
                }
                else {
                    if(cnt < 2) {
                        board2[i][j] = 0;
                    }
                    if(cnt > 3) {
                        board2[i][j] = 0;
                    }
                }
            }
        }
        board = board2;
    }
    int checkCountOfNeighborLiveCell(vector<vector<int>>& board, int i, int j, int dimOut, int dimIn) {
        int cnt = 0;
        for(int x=-1;x<2;++x) {
            for(int y=-1;y<2;++y) {
                if(i+x < dimOut && i+x>=0 && j+y < dimIn && j+y >=0 && (x!=0 || y!=0)) {
                    if(board[i+x][j+y] == 1) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

