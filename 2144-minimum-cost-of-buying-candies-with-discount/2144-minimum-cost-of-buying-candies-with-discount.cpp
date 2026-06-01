class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(),cost.rend());
        int totalcost = 0;
        int x = 0;
        for(int i = 0;i < cost.size();i++){
            x++;
            if(x == 3){
                x = 0;
                continue;
            }
            totalcost += cost[i];
        }
        return totalcost;
    }
};