class Solution {
public:
/*
map+string的构造+暴力
*/
    int num[1005],a[1005];
    bool flag=false;
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        if(words.size()==0||s.size()==0)return ans;
        int ed=s.size()-words.size()*words[0].size(),ln=words[0].size(),index=1;
        map<string,int>mp;
        for(int i=0;i<words.size();i++){
            if(mp[words[i]]==0)mp[words[i]]=index++;
        }
        for(int i=0;i<words.size();i++){
            a[mp[words[i]]]++;
        }
        for(int i=0;i<=ed;i++){
            memset(num,0,sizeof(num));
            string temp=string(s,i,words[0].size()*words.size());
            flag=true;
            for(int j=0;j<words.size();j++){
                string te=string(temp,j*ln,ln);
                if(mp[te]==0){
                    flag=false;break;
                }
                num[mp[te]]++;
            }
            if(flag){
                for(int i=1;i<index;i++){
                    printf("%d %d %d\n",ed,num[i],a[i]);
                    if(num[i]!=a[i]){
                        flag=false;break;
                    }
                }
            }
            if(flag)ans.push_back(i);
        }
        return ans;
    }
};