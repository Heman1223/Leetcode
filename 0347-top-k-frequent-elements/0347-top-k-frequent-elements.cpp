class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k == nums.size()){
            return nums;
        }
        map<int,int> freq;
        for(int num : nums){
            freq[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        for(pair<int,int> p: freq){
            minHeap.push({p.second,p.first});
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        vector<int> top(k);
        for(int i = k - 1;i >= 0;i--){
            top[i] = minHeap.top().second;
            minHeap.pop();
        }
        return top;

    }
};