class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        vector<int>b(a.begin(),a.end());
        sort(b.begin(),b.end());
        int n=a.size();
        int l=1e8,r=-1e8;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                l=min(l,i);
                r=max(r,i);
            }
        }
        if(l<=r)return r-l+1;
        else return 0;
    }
};
// [2,6,4,8,10,9,15]
// [2,4,6,8,9,10,15]