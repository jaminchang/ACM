class Solution {
public:
/*
字符串转换 动态规划
dp[i][j]表示从长度i到长度j所需要的次数
*/
    int minDistance(string word1, string word2) {
        int dp[1005][1005];
        int m=word1.size(),n=word2.size();
        for(int i=0;i<=word1.size();i++)dp[i][0]=i;
        for(int j=0;j<=word2.size();j++)dp[0][j]=j;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1])dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=dp[i-1][j-1]+1;
                dp[i][j]=min(dp[i-1][j]+1,dp[i][j]);
                dp[i][j]=min(dp[i][j-1]+1,dp[i][j]);
            }
        }
        return dp[m][n];
    }
};