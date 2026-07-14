class Solution {
public:
    vector<int>p,r;
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        p.resize(n + 1);
        r.resize(n + 1,1);

        for(int i = 0;i < n;i++) p[i] = i;

        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            Union(u,v);
        }

        return find(source) == find(destination);
    }

    int find(int i){
        if(p[i] == i) return i;
        return p[i] = find(p[i]);
    }

    void Union(int x,int y){
        int px = find(x);
        int py = find(y);
        
        if(px == py) return;
        if(r[px] > r[py]){
            p[py] = px;
        }else if(r[px] < r[py]){
            p[px] = py;
        }else{
            p[py] = px;
            r[px]++;
        }
    }
};