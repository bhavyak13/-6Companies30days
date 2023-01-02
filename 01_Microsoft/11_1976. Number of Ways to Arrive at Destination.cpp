#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ai array<ll,2>
struct cmparr {constexpr bool operator()(array<ll, 2> const& a,array<ll, 2>  const& b)const noexcept{return a[0] > b[0];}};

class Solution {
public:
    ll mod=1000000007;
    int countPaths(int n, vector<vector<int>>& gx) {
        vector<vector<ai>>g(n,vector<ai>());
        for(auto i:gx){
            g[i[0]].push_back({i[1],i[2]});
            g[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<ai,vector<ai>,cmparr>pq;
        vector<ll>dis(n,1e15);
        vector<ll>ways(n,1);
        pq.push({0,0});
        dis[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            ll r=x[1],d=x[0];
            if(d>dis[r])continue;
            for(auto i:g[r]){
                ll tr=i[0];
                ll nd=d+i[1];
                if(dis[tr]>nd){
                    dis[tr]=nd;
                    ways[tr]=ways[r];
                    pq.push({nd,tr});
                }else if(dis[tr]==nd){
                    ways[tr]=((ways[r]+ways[tr])%mod);
                }
            }
        }
        return ways[n-1];
    }
};