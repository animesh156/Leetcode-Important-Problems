class Solution {
public:
    int gcd(int a,int b){
          return b == 0 ? a : gcd(b,a % b);
    }

    int subarrayLCM(vector<int>& nums, int k) {
        int cnt= 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
             long long lcm = nums[i];
             if(lcm == k) cnt++;
            for(int j=i+1;j<n;j++){
                
                lcm = (lcm * nums[j]) / gcd(lcm,nums[j]);

                if(lcm > k) break;

                if(lcm == k) cnt++;
                  
            }
        }

        return cnt;
    }
};
