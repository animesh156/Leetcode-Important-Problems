class Solution {
public:
   int getNext(int n){
    int sum = 0;
    while(n){
        int d = n % 10;
        n /= 10;
        sum += d * d;
    }
    return sum;
   }

    bool isHappy(int n) {
      unordered_set<int> seen;
      while(n != 1 && !seen.count(n)){   // at max it can have sum of sqaures is 81 * d
        seen.insert(n);
        n = getNext(n);
      }
       return n == 1;
    }
};
