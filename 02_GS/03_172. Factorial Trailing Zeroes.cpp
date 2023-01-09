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
    int trailingZeroes(int n) {
        int N=5,ans=0;
        while(N<=n){
            ans+=n/N;
            N*=5;
        }
        return ans;
    }
}; 