// memo using unordered map TC:- O(logn), SWC :- O(n)
class Solution {
public:
    unordered_map<long long,int> dp;
    int f(long long n){
        if(n == 1) return 0;
        if(dp.count(n)) return dp[n];
        if(n % 2 == 0){
            return dp[n] = 1 + f(n / 2);
        }
        return dp[n] = 1 + min(f((long long)n+1), f(n-1)); 
    }
    int integerReplacement(int n) {
        return f((long long)n);
    }
};


// grredy apporach O(logn)   
// cocnept is we look for tailing zeros in case of odd number which option produc more tailing zeroes, more tailing zeros means more no of / 2 steps to reach next odd no, but here is catrhc if (n+1) alwsy gives more trailing zeros but in two casaes like n == 3 or num & 2 == 0(where 2nd LSWB is ) gives more trailing option so in thi casse we prefer n - 1
class Solution {
public:
    int integerReplacement(int n) {
        long long num = n;
        int steps = 0;
        while(num > 1){
            if(num % 2 == 0) num /= 2;
            else {
              if(num == 3 || (num & 2) == 0) num -= 1;
              else num += 1;
            }
            steps++;
        }
        return steps;
    }
};
