class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        string binary = "";

        // convert to binary
        while(n > 0){
            binary.push_back((n % 2) + '0');
            n /= 2;
        }

        reverse(binary.begin(), binary.end());

        // complement bits
        for(int i = 0; i < binary.size(); i++){
            if(binary[i] == '0')
                binary[i] = '1';
            else
                binary[i] = '0';
        }

        // convert back to decimal
        int ans = 0;
        for(int i = 0; i < binary.size(); i++){
            ans = ans * 2 + (binary[i] - '0');
        }

        return ans;
    }
};