class Solution {
public:
    /*
    简单粗暴
     */
    int firstMissingPositive(vector<int>& nums) {
        int a[1000005];
        memset(a,0,sizeof(a));
        for(int i=0;i<nums.size();i++){
            if(nums[i]>1000000||nums[i]<0)continue;
            a[nums[i]]++;
        }
        for(int i=1;;i++){
            if(a[i]==0)return i;
        }
    }
};