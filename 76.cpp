class Solution {
public:
/*
string构造函数接收string,开始，长度
只要第一次判断成功了，后面的就不用一直调用judge函数判断了

*/
    int num[300],jug[300];
    bool f=false;
    string minWindow(string s, string t) {
        for(int i=0;i<t.size();i++)jug[t[i]]++;
        int l=0,r=0,te=0,ans=100000000;
        for(int i=0;i<s.size();i++){
            num[s[i]]++;
            while(te<i&&((jug[s[te]]&&num[s[te]]>jug[s[te]])||(!jug[s[te]]))){
                num[s[te]]--;
                te++;
            }
            if(f||judge(t)){
                if(i-te<ans){
                    ans=i-te;l=te;r=i+1;
                }
                f=true;
            }
        }

        while(te<s.size()&&((jug[s[te]]&&num[s[te]]>1)||!jug[s[te]])){
                num[s[te]]--;
                te++;
            }
            if(judge(t)){
                if(s.size()-te<ans){
                    ans=s.size()-te;l=te;r=s.size();
                }
            }
        return string(s,l,r-l);
    }

    bool judge(string t){
        for(int i=0;i<t.size();i++){
            if(num[t[i]]<jug[t[i]])return false;
        }
        return true;
    }
};