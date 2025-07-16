class Solution {
public:
    double f(double x, long long N){
        if(N == 0) return 1;

        double half = f(x,N/2);

        if(N % 2 != 0) return half * half * x;
        else return half * half;
    }

    double myPow(double x, int n) {
        long long N = n;
        if(N < 0){
            N = -N;
            x = 1 / x;
        }

        return f(x,N);
    }
};
