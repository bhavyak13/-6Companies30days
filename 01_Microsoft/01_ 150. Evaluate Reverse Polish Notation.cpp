class Solution {
public:
    #define ll long long
    int evalRPN(vector<string>& tokens) {
        stack<ll>stk;
        for(auto i:tokens){
            if(i=="+"){
                ll b=stk.top();
                stk.pop();
                ll a=stk.top();
                stk.pop();
                stk.push(a+b);
            }
            else if(i=="-"){
                ll b=stk.top();
                stk.pop();
                ll a=stk.top();
                stk.pop();
                stk.push(a-b);
            }
            else if(i=="/"){
                ll b=stk.top();
                stk.pop();
                ll a=stk.top();
                stk.pop();
                stk.push(a/b);
            }
            else if(i=="*"){
                ll b=stk.top();
                stk.pop();
                ll a=stk.top();
                stk.pop();
                stk.push(a*b);
            }
            else{
                ll x=stoi(i);
                stk.push(x);
            }
        }
        return stk.top();
    }
};