class Solution {
public:
/*
直接模拟就行，循环一遍，如果第二个不符合就直接换掉，最后次数是最优的
 */
    int minSwapsCouples(vector<int>& row) {
        int pos[100],temp;
        for(int i=0;i<row.size();i++)pos[row[i]]=i;
        int cnt=0;
        for(int i=0;i<row.size();i+=2){
            if(row[i+1]!=get(row[i])){
                temp=pos[get(row[i])];
                row[pos[get(row[i])]]=row[i+1];
                row[i+1]=get(row[i]);
                pos[row[temp]]=temp;
                pos[row[i+1]]=i+1;
                cnt++;
            }
        }
        return cnt;
    }
    int get(int x){
        if((x+1+x)%4==1)return x+1;
        return x-1;
    }
};