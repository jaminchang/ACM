class Solution {
public:
/*
存在空的输入，实属恶心人
*/
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)return 0;
        int a[2005][2005],up[2005][2005],dn[2005][2005];
        for(int i=0;i<matrix.size();i++){
            a[i][0]=matrix[i][0]-'0';
            for(int j=1;j<matrix[i].size();j++){
                if(matrix[i][j]=='1')a[i][j]=a[i][j-1]+1;
                else a[i][j]=0;
            }
        }
        int ans=0;
        stack<int>st;
        for(int j=0;j<matrix[0].size();j++){
            while(!st.empty())st.pop();
            for(int i=0;i<matrix.size();i++){
                if(st.empty()){
                    st.push(i);
                    up[i][j]=-1;
                }
                else{
                    while(!st.empty()&&a[st.top()][j]>=a[i][j])st.pop();
                    if(!st.empty())up[i][j]=st.top();
                    else up[i][j]=-1;
                    st.push(i);
                }
            }
        }
        for(int j=matrix[0].size()-1;j>=0;j--){
            while(!st.empty())st.pop();
            for(int i=matrix.size()-1;i>=0;i--){
                if(st.empty()){
                    st.push(i);
                    dn[i][j]=matrix.size();
                }
                else{
                    while(!st.empty()&&a[st.top()][j]>=a[i][j])st.pop();
                    if(!st.empty())dn[i][j]=st.top();
                    else dn[i][j]=matrix.size();
                    st.push(i);
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                ans=max(ans,(dn[i][j]-up[i][j]-1)*a[i][j]);
                printf("%d %d %d %d %d\n",i,j,up[i][j],dn[i][j],a[i][j]);
            }
        }
        return ans;
    }
};