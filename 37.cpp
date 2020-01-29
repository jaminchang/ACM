class Solution {
    /*
    用0开始的作位置，1开始的作数独号
     */
public:
    int row[12][12],col[12][12],ar[12][12];
    char mp[12][12];
    bool flag=false;
    void solveSudoku(vector<vector<char>>& board) {
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(ar,0,sizeof(ar));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    row[i][board[i][j]-'0']=1;
                    col[j][board[i][j]-'0']=1;
                    ar[area(i,j)][board[i][j]-'0']=1;
                }
            }
        }
        dfs(board,0);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)
                board[i][j]=mp[i][j];
        }
    }

    void dfs(vector<vector<char>>& board,int n){
        if(flag)return;
        if(n==81){
            flag=true;return;
        }
        int x=n/9;
        int y=n%9;
        if(board[x][y]=='.'){
            for(int i=1;i<=9;i++){
                if(row[x][i]==0&&col[y][i]==0&&ar[area(x,y)][i]==0){
                    row[x][i]=1;
                    col[y][i]=1;
                    ar[area(x,y)][i]=1;
                    mp[x][y]='0'+i;
                    dfs(board,n+1);
                    if(flag)return;//要结束的，忘了就错了
                    row[x][i]=0;
                    col[y][i]=0;
                    ar[area(x,y)][i]=0;
                }
            }
        }
        else{
            mp[x][y]=board[x][y];
            dfs(board,n+1);
        }
    }

    int area(int x,int y){
        return x/3*3+y/3;
    }
};