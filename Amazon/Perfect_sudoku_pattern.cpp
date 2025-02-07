class Solution {
public:

    bool Traverse(vector<vector<char>>& board, int sr, int er, int sc, int ec){
        set<int>st;
        for(int row=sr; row<=er; row++){
            for(int col=sc; col<=ec; col++){
                if(board[row][col]=='.') continue;
                if(st.find(board[row][col])!=st.end()) return false;
                else st.insert(board[row][col]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row=0; row<9; row++){
            set<int>st;
            for(int col=0; col<9; col++){
                if(board[row][col]=='.') continue;
                if(st.find(board[row][col])!=st.end()) return false;
                else st.insert(board[row][col]);
            }
        }
        for(int col=0; col<9; col++){
            set<int>st;
            for(int row=0; row<9; row++){
                if(board[row][col]=='.') continue;
                if(st.find(board[row][col])!=st.end()) return false;
                else st.insert(board[row][col]);
            }
        }
        for(int sr=0; sr<9; sr+=3){
            int er = sr+2;
            for(int sc=0; sc<9; sc+=3){
                int ec = sc+2;
                if(!Traverse(board, sr, er, sc, ec))return false;
            }
        }
        return true;
    }
};