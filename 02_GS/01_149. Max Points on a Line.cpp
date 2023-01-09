/*
    Author : Bhavya Kawatra
 Institute : MAIT
      Dept : CST
     Email : bhavyakawatra6@gmail.com
 CF handle : BhavyaKawatra13
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& a) {
        int n=a.size();
        #define db double
        unordered_map<db,int>m;
        for(int i=0;i<n;i++){
            unordered_map<db,int>M;
            for(int j=i+1;j<n;j++){
                db x=a[j][0]-a[i][0];
                db y=a[j][1]-a[i][1];
                db slope=1e9;
                if(x)slope=y/x;
                M[slope]++;
            }
            for(auto i:M){
                m[i.first]=max(m[i.first],i.second);
            }
        }
        int mx=0;
        for(auto i:m){
            mx=max(mx,i.second);
        }    
        return mx+1;
    }
};
