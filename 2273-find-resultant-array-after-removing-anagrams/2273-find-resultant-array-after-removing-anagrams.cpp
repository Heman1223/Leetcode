class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        
        // Always include the first word
        ans.push_back(words[0]); 
        
        for (int i = 1; i < words.size(); i++) {
            string current = words[i];
            string previous = words[i - 1];
            
            // Sort both to check if they are anagrams
            sort(current.begin(), current.end());
            sort(previous.begin(), previous.end());
            
            // If they are NOT anagrams, the current word is kept
            if (current != previous) {
                ans.push_back(words[i]);
            }
        }
        
        return ans;
    }
};
