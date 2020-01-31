class Solution {
    /*
    把正确的去掉，剩下不匹配的位置信息，求最大值
     */
public:
    int longestValidParentheses(string s) {
        stack<pair<char,int>>st;
        bool flag=false;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(make_pair('(',i));
            }
            else{
                if(!st.empty()&&st.top().first=='('){
                    st.pop();
                }
                else{
                    st.push(make_pair(')',i));
                }
            }
        }
        vector<int>v;
        v.push_back(s.size());
        while(!st.empty()){
            v.push_back(st.top().second);
            st.pop();
        }
        v.push_back(-1);
        for(int i=v.size()-1;i>=1;i--){
            ans=max(v[i-1]-v[i]-1,ans);
        }
        return ans;
    }
};