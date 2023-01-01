class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& a) {
        vector<vector<int>>g(v,vector<int>());
        queue<int>q;
        vector<int>ind(v,0);
        for(auto i:a){
            g[i[1]].push_back(i[0]);
            ind[i[0]]++;
        }
        for(int i=0;i<v;i++){
            if(!ind[i])q.push(i);
        }
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            for(auto i:g[x]){
                ind[i]--;
                if(!ind[i])q.push(i);
            }
        }
        for(auto i:ind){
            if(i)return false;
        }
        return true;
    }
};