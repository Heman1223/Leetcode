class Solution {
public:
    bool isValid(string word) {
    if (word.size() < 3) return false;  // Rule 1

    bool hasVowel = false, hasConsonant = false;

    for (char c : word) {
        if (!isalnum(c)) return false;  // Rule 2

        if (isalpha(c)) {
            char lower = tolower(c);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                hasVowel = true;  // Rule 3
            } else {
                hasConsonant = true;  // Rule 4
            }
        }
    }

    return hasVowel && hasConsonant;
}

};