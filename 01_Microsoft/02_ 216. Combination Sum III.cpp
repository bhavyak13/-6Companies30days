class Solution {
public:
    int dp[10]{0};
    int k,n;
    vector<vector<int>>ans;
    void ok(){
        vector<int>a;
        for(int i=0;i<10;i++){
            if(dp[i])a.push_back(i);
        }
        ans.push_back(a);
    }
    void fun(int curr,int steps,int last){
        if(steps==k-1){
            int rem=n-curr;
            if(rem>last&&rem<10&&!dp[rem]){
                dp[rem]=1;
                ok();
                dp[rem]=0;
            }
            return;
        }
        for(int i=last+1;i<10;i++){
            curr+=i;
            dp[i]=1;
            fun(curr,steps+1,i);
            dp[i]=0;
            curr-=i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        memset(dp,0,sizeof(dp));
        this->k=k;
        this->n=n;
        fun(0,0,0);
        return ans;
    }
};