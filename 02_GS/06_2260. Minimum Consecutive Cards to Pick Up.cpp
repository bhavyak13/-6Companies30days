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
    int minimumCardPickup(vector<int>& cards) {
        int mn=1e9;
        int M[1000006]{0};
        int indx=1;
        for(auto i:cards){
            if(M[i]){
                mn=min(mn,indx-M[i]+1);
            }
            M[i]=indx;
            indx++;
        }
        return mn==1e9?-1:mn;
    }
};