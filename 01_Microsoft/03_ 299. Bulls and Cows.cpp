class Solution {
public:
    string getHint(string s, string g) {
        int b=0,c=0;
        int n=s.size();
        int dp1[10]{0};
        int dp2[10]{0};
        for(int i=0;i<n;i++){
            if(s[i]==g[i])b++;
            else{
                dp1[s[i]-'0']++;
                dp2[g[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++){
            c+=min(dp1[i],dp2[i]);
        }
        return to_string(b)+'A'+to_string(c)+'B';
    }
};