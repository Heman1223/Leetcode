class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for(int i = 2;i <= n;i++){
            if(i == 2 || i == 5 || i == 6 || i == 9){
                count++;
            }
            if(i > 10){
                bool flag = false;
                int temp = i;
                while(temp != 0){
                    int rem = temp%10;
                    if(rem == 2 || rem == 5 || rem == 6 || rem == 9){
                        flag = true;
                    }else if(rem == 3 || rem == 7 || rem == 4){
                        flag = false;
                        break;
                    }
                    temp /= 10;
                }
                if(flag) count ++;
            }
        }
        return count;
    }
};