class Solution {
public:
    void dfs(int room,vector<vector<int>>& rooms,vector<bool> &vis){
        vis[room] = true;
        for(auto it : rooms[room]){
            if(!vis[it]){
                dfs(it,rooms,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n);
        dfs(0,rooms,vis);
        for(bool it : vis){
            if(it == false) return false;
        }
        return true;
    }
};