class Solution {
public:
    struct Compare {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) {
            if (a.first == b.first) {
                return a.second > b.second; // keep smaller lex first
            }
            return a.first < b.first; // max-heap (largest freq first)
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for (string& s : words) {
            freq[s]++;
        }

        priority_queue<pair<int,string>, vector<pair<int,string>>, Compare> maxHeap;
        for (auto& p : freq) {
            maxHeap.push({p.second, p.first});
        }

        vector<string> result;
        for (int i = 0; i < k; i++) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
};