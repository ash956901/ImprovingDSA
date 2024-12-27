class Solution {
    const long long MOD = 1e9 + 7;

    long long modExp(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
public:
    int countGoodNumbers(long long n) {
   
        long long oddCount = (n + 1) / 2; 
        long long evenCount = n / 2;    

        long long even = modExp(5, oddCount, MOD); 
        long long odd = modExp(4, evenCount, MOD);  

        long long ans = (even * odd) % MOD;        
        return (int)ans;
    }
};