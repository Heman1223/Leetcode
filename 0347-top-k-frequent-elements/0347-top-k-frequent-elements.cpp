class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i : nums){
            mp[i]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto &it : mp){
            int freq = it.second;
            int num = it.first;
            pq.push({freq,num});
        }
        vector<int> ans;
        for(int i = 0; i < k;i++){
            pair front = pq.top();
            pq.pop();

            ans.push_back(front.second);
        }
        return ans;
    }
};