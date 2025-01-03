class Solution {
public:
    bool solve(vector<vector<char>>& board,string &curr,int i,int j,string &word,vector<vector<bool>> &visited){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()){
            if(curr==word) return true;
            return false;
        }
        if(curr==word) {
            return true;}

        char cChar=word[curr.size()];

        //explore all four options
        bool a=false;
        bool b=false;
        bool c=false;
        bool d=false;

        visited[i][j]=true;

        if(i-1>=0 && board[i-1][j]==cChar && !visited[i-1][j]){
            curr.push_back(cChar);
            a=solve(board,curr,i-1,j,word,visited);
            curr.pop_back();
        }

         if(i+1<board.size() && board[i+1][j]==cChar  && !visited[i+1][j]){
            curr.push_back(cChar);
            b=solve(board,curr,i+1,j,word,visited);
              curr.pop_back();
        }

        if(j+1<board[0].size() && board[i][j+1]==cChar  && !visited[i][j+1]){
             curr.push_back(cChar);
             c=solve(board,curr,i,j+1,word,visited);
              curr.pop_back();
        }


        if(j-1>=0 && board[i][j-1]==cChar  && !visited[i][j-1]){
             curr.push_back(cChar);
             d=solve(board,curr,i,j-1,word,visited);
              curr.pop_back();
        }

        visited[i][j]=false;
        return (a||b||c||d);


    }
    bool exist(vector<vector<char>>& board, string word) {
        string temp="";
       
        //find the first char 
        vector<vector<bool>> visited(board.size(),vector<bool> (board[0].size(),false));
        bool ans=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    temp.push_back(word[0]);
                    ans=ans|| solve(board,temp,i,j,word,visited);
                    temp.pop_back();
                }
            }
        }
        return ans;
    }
};