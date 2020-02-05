class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int l[1005][1005],r[1005][1005],up[1005][1005],a[1005][1005];
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                l[i][j]=r[i][j]=0;up[i][j]=0;
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=1;j<matrix[i].size();j++){
                if(matrix[i][j-1]=='1')l[i][j]=l[i][j-1]+1;
            }
            for(int j=matrix[i].size()-2;j>=0;j--){
                if(matrix[i][j+1]=='1')r[i][j]=r[i][j+1]+1;
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(i>=1&&matrix[i-1][j]=='1'&&matrix[i][j]=='1'){
                    up[i][j]=up[i-1][j]+1;
                    l[i][j]=min(l[i-1][j],l[i][j]);
                    r[i][j]=min(r[i-1][j],r[i][j]);
                }
                if(matrix[i][j]=='0')continue;
                ans=max(ans,(l[i][j]+r[i][j]+1)*(up[i][j]+1));
                printf("%d %d %d %d %d\n",i,j,l[i][j],r[i][j],up[i][j]);
            }
        }
        return ans;
    }
};