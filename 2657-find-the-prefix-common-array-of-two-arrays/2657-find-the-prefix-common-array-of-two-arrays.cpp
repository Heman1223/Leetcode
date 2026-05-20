class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> ans(n);
        vector<int> freq(n + 1, 0);

        int common = 0;

        for (int i = 0; i < n; i++) {

            freq[A[i]]++;
            if (freq[A[i]] == 2)
                common++;

            freq[B[i]]++;
            if (freq[B[i]] == 2)
                common++;

            ans[i] = common;
        }

        return ans;
    }
};

// class Solution {
// public:
//     vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
//         int common = 0;
//         int n = A.size();
//         set<int> setA;
//         set<int> setB;
//         vector<int> c(n);
//         for(int i = 0;i < A.size();i++){
//             setA.insert(A[i]);
//             setB.insert(B[i]);
//             if(A[i] == B[i]){
//                 common++;
//                 c[i] = common;
//                 continue;
//             }
//             if(setA.count(B[i])){
//                 common++;
//             }
//             if(setB.count(A[i])){
//                 common++;
//             }
//             c[i] = common;
//         }
//         return c;
//     }
// };