#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>ordered_set;

#define ub upper_bound
#define all(v) v.begin(),v.end()
#define pb push_back
#define sz size()
class Solution {
public:
    long long numberOfPairs(vector<int>& a, vector<int>& b, int diff) {
        int n=a.size();
        long long c=0;
        ordered_set t;
        for(int i=0;i<n;i++){
            c+=t.order_of_key(a[i]-b[i]+1);
            t.insert(a[i]-b[i]-diff);
        }
        return c;
    }
};