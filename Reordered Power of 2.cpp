class Solution {
public:
    string f(int x){
         string freq(10,'0');
         while(x!=0){
            freq[x % 10]++;
            x /= 10;
         }
         return freq;
    }

    bool reorderedPowerOf2(int n) {
        string target = f(n);
        for(int i=0;i<31;i++){
            if(f(1 << i) == target) return true;
        }
        return false;
    }
};
