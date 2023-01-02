int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);}
class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& b) {
        int n=a.size();
        priority_queue<int,vector<int>,greater<int>>pq(a.begin(),a.end());
        int g=b[0];
        for(auto i :b){
            g=gcd(g,i);
        }
        while(!pq.empty()){
            auto x=pq.top();
            if(g%x==0)return n-pq.size();
            pq.pop();
        }
        return -1;
    }
};