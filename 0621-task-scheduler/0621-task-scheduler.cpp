class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);
        priority_queue<int> pq;

        for(int i = 0; i < tasks.size();i++){
            freq[tasks[i] - 'A']++;
        }
        for(int i = 0; i < 26;i++){
            if(freq[i] > 0){
                pq.push(freq[i]);
            }
        }

        int ans = 0;
        while(!pq.empty()){
            
            int taskcycle = 0;
            int cycle = n + 1;

            vector<int> temp;

            while(cycle > 0 && !pq.empty()){
                int currtask = pq.top();
                pq.pop();
                if(currtask > 1){
                    temp.push_back(currtask - 1);
                }
                taskcycle++;
                cycle--;
            }
            for(int ele : temp){
                pq.push(ele);
            }

            ans += pq.empty() ? taskcycle : n + 1;
        }
        return ans;
    }
};