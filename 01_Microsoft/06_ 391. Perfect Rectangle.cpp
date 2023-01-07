/*

-> The right answer must satisfy two conditions:

1. the large rectangle area should be equal to the sum of small rectangles
2. count of all the points should be even, and that of all the four corner points should be one

*/
class Solution {
public:
    #define ll long long
    bool isRectangleCover(vector<vector<int>>& a) {
        int trX=-1e9,trY=-1e9,blX=1e9,blY=1e9;
        map<array<int,2>,int>m;
        ll area=0;
        for(auto i:a){
            trX=max(trX,i[2]);
            trY=max(trY,i[3]);
            blX=min(blX,i[0]);
            blY=min(blY,i[1]);
            area+=((ll)(i[2]-i[0]))*((ll)(i[3]-i[1]));
            if(m.find({i[0],i[1]})!=m.end())m.erase({i[0],i[1]});
            else m[{i[0],i[1]}]++;
            if(m.find({i[0],i[3]})!=m.end())m.erase({i[0],i[3]});
            else m[{i[0],i[3]}]++;
            if(m.find({i[2],i[3]})!=m.end())m.erase({i[2],i[3]});
            else m[{i[2],i[3]}]++;
            if(m.find({i[2],i[1]})!=m.end())m.erase({i[2],i[1]});
            else m[{i[2],i[1]}]++;
        }
        if(m.size()!=4||!(m[{trX,trY}])||
        !(m[{blX,blY}])||
        !(m[{trX,blY}])||
        !(m[{blX,trY}]))return false;
        return area==((ll)(trY-blY)*(ll)(trX-blX));
    }
};