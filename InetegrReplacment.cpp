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
