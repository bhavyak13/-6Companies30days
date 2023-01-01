
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back

class Solution {
public:
    vvi g;
    int bob;
    int bbindx=0;
    vector<int>mns;
    vector<int>dp,a;
    bool dfs(int root,int prnt){
        for(auto i:g[root]){
            if(i==prnt)continue;
            if(i==bob){
                mns[i]=bbindx++;
                return false;
            }
            bool x=dfs(i,root);
            if(!x){
                mns[i]=bbindx++;
                return false;
            }
        }
        return true;
    }
    int dfss(int root,int prnt,int t){
        int mx=-1e8;
        for(auto i:g[root]){
            if(i==prnt)continue;
            mx=max(mx,dfss(i,root,t+1));
        }
        int cost=a[root];
        if(mns[root]==t){
            cost/=2;
        }else if(mns[root]<t&&mns[root]!=-1){
            cost=0;
        }
        return dp[root]=(mx==-1e8?0:mx)+cost;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bb, vector<int>& am) {
        bob=bb;
        a=am;
        g.assign(100005,vi());
        dp.assign(100005,0);
        mns.assign(100005,-1);
        for(auto i:edges){
            g[i[0]].pb(i[1]);
            g[i[1]].pb(i[0]);
        }
        dfs(0,-1);
        mns[0]=bbindx;
        dfss(0,-1,0);
        return dp[0];
    }
};