class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int l[100005],r[100005];
        for(int i=0;i<heights.size();i++){
            if(st.empty()){
                st.push(i);
                l[i]=-1;
            }
            else{
                while(!st.empty()&&heights[st.top()]>=heights[i])st.pop();
                if(!st.empty())l[i]=st.top();
                else l[i]=-1;
                st.push(i);
            }
        }
        while(!st.empty())st.pop();
        for(int i=heights.size()-1;i>=0;i--){
            if(st.empty()){
                st.push(i);
                r[i]=heights.size();
            }
            else{
                while(!st.empty()&&heights[st.top()]>=heights[i])st.pop();
                if(!st.empty())r[i]=st.top();
                else r[i]=heights.size();
                st.push(i);
            }
        }
        int ans=0;
        for(int i=0;i<heights.size();i++){
            ans=max(ans,(r[i]-l[i]-1)*heights[i]);
            printf("%d %d %d\n",i,l[i],r[i]);
        }
        return ans;
    }
};