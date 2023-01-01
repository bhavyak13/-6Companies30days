class Solution {
public:
#define ll long long
    int maxRotateFunction(vector<int>& a) {
        ll n=a.size();
        vector<ll>dp(n,0);
        ll s=0,f=0,ans=-1e11;
        for(int i=0;i<n;i++){
            s+=a[i];
            f+=i*a[i];
        }
        ans=max(ans,f);
        for(int i=1;i<n;i++){
            f+=s-(n*a[n-i]);
            ans=max(ans,f);
        }
        return ans;
    }
};
/*

more a mathematic problem:
Fk.    = 0 * Ak[0] + 1 * Ak[1] + ... + (n-1) * Ak[n-1]
F(k-1)  = 0 * Ak-1[0] + 1*Ak-1[1] + ... + (n-1)* Ak-1[n-1]
// Ak[1] that is in Ak-1[0]
        = 0 * Ak[1] + 1*Ak[2] + ... + (n-2) * aK[n-1] + (n-1) * aK[0];

now 
Fk - F(k-1) = 0*Ak + (Ak[1]+Ak[2]+...+Ak) - (n-1)Ak[0]
Fk - F(k-1) = SUM-Ak[0] - (n-1)Ak[0]
Fk - F(k-1) = SUM(-Ak[0] +Ak[0]) - nAk[0]
Fk - F(k-1) = SUM - nAk[0]
Fk = F(k-1) + SUM - nAk[0]

for k=0

ak[0] = A[0]
ak[1] = A[N-1]
ak[2] = A[N-2]
ak[N-1] = A[1]



k-1 -> a b c d
k ->     a b c d

ak[i] = ak-1[i-1]



*/