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
    #define db double
    db dis(vector<int>a,vector<int>b){
        db x=b[0]-a[0],y=b[1]-a[1];
        return sqrt(x*x+y*y);
    }
    int numberOfBoomerangs(vector<vector<int>>& a) {
        int n=a.size();
        db ans=0;
        for(int i=0;i<n;i++){
            unordered_map<db,int>m;
            for(int j=0;j<n;j++){
                m[dis(a[i],a[j])]++;
            }
            for(auto i:m){
                ans+=i.second*(i.second-(db)1);
            }
        }
        return ans;
    }
};