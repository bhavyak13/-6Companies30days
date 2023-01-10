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
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto i:nums)m[i]++;
        unordered_map<int,int>last;
        for(auto i:nums){
            if(!m[i])continue;
             if(last[i-1]){
                last[i-1]--;
                last[i]++;
                m[i]--;
            }
            else if(m[i+1]&&m[i+2]){
                m[i]--;m[i+1]--;m[i+2]--;
                last[i+2]++;
            }else return false;
        }
        return true;
    }
};