class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>l,r;
        int temp=0;
        for(int i=0;i<height.size();i++){
            l.push_back(temp);
            temp=max(temp,height[i]);
        }
        temp=0;
        for(int j=height.size()-1;j>=0;j--){
            r.push_back(temp);//这个地方是反的
            temp=max(temp,height[j]);
        }
        int ans=0;
        for(int i=0;i<height.size();i++){
            int h=min(l[i],r[height.size()-i-1]);//这里要反过来写
            if(h>height[i]){
                ans+=h-height[i];
            }
        }
        return ans;
    }
};