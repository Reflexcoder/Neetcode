class Solution {
public:
    bool dfs(vector<vector<char>>&board, string &word,int n, int m,int index){
            if(index==word.length()){
                return true;
            }
            if(n<0 || n>=board.size() || m <0 || m>=board[0].size() || board[n][m]!=word[index]){
                return false;
            }
            char temp=board[n][m];
            board[n][m]='#';
            bool found= dfs(board,word,n+1,m,index+1) || dfs(board,word,n-1,m,index+1) || dfs(board,word,n,m+1,index+1) || dfs(board,word,n,m-1,index+1);
            board[n][m]=temp;

            return found;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(board[i][j]==word[0] && dfs(board,word,i,j,0)){
                return true;
              }
            }
        }
        return false;

    }
};
