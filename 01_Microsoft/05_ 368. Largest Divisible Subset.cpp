class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        sort(a.begin(),a.end());
        int n=a.size();
        vector<int>prnt(n,-1);
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i]%a[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        prnt[i]=j;
                    }
                }
            }
        }
        int indx=max_element(dp.begin(),dp.end())-dp.begin();
        vector<int>ans;
        while(indx!=-1){
            ans.push_back(a[indx]);
            indx=prnt[indx];
        }
        return ans;
    }
};