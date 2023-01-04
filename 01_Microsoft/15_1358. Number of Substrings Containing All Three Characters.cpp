class Solution {
public:
    int numberOfSubstrings(string s) {
        int prev=0,curr=0,n=s.size(),ans=0;
        int dp[3]{0};
        while(curr<n){
            if(!dp[0]||!dp[1]||!dp[2]){
                dp[s[curr]-'a']++;
            }
            while(dp[0]&&dp[1]&&dp[2]){
                ans+=n-curr;
                dp[s[prev]-'a']--;
                prev++;
            }
            curr++;
        }
        return ans;
    }
};