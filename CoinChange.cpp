// Memoziation
class Solution {
public:
     int f(int idx,vector<int>& coins,int tar,vector<vector<int>>&dp){
        if(tar == 0) return 0;
        if(idx == 0){
            if(tar % coins[0] == 0) return tar / coins[0];
            return 1e9;
        }

        if(dp[idx][tar] != -1) return dp[idx][tar];

        int notTake = f(idx - 1, coins, tar,dp);
        int take = 1e9;
        if(coins[idx] <= tar) take = 1 + f(idx, coins, tar - coins[idx],dp);

        return dp[idx][tar] = min(take, notTake);
     }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1,-1));
         int minAmount = f(coins.size()-1,coins,amount,dp);
         return minAmount == 1e9 ? - 1 : minAmount;
    }
};

// Tabulation 
class Solution {
public:
     int f(int idx,vector<int>& coins,int tar,vector<vector<int>>&dp){
        if(tar == 0) return 0;
        if(idx == 0){
            if(tar % coins[0] == 0) return tar / coins[0];
            return 1e9;
        }

        if(dp[idx][tar] != -1) return dp[idx][tar];

        int notTake = f(idx - 1, coins, tar,dp);
        int take = 1e9;
        if(coins[idx] <= tar) take = 1 + f(idx, coins, tar - coins[idx],dp);

        return dp[idx][tar] = min(take, notTake);
     }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1,0));
        for(int i=0;i<=amount;i++){
            if(i % coins[0] == 0) dp[0][i] = i / coins[0];
            else dp[0][i] = 1e9;
        }

        for(int idx = 1; idx < coins.size();idx++){
            for(int tar = 0; tar <= amount;tar++){

                int notTake = dp[idx-1][tar];
                int take = 1e9;
                if(coins[idx] <= tar){
                    take = 1 + dp[idx][tar - coins[idx]];
                }

                dp[idx][tar] = min(take,notTake);
            }
        }

        int minCoins = dp[coins.size()-1][amount];
        return minCoins == 1e9 ? -1 : minCoins;
    }
};

// space otpimze 
class Solution {
public:
  
    int coinChange(vector<int>& coins, int amount) {
         vector<int> prev(amount + 1,0);

        for(int i=0;i<=amount;i++){
            if(i % coins[0] == 0) prev[i] = i / coins[0];
            else prev[i] = 1e9;
        }

        for(int idx = 1; idx < coins.size();idx++){
             vector<int> cur(amount + 1,0);
            for(int tar = 0; tar <= amount;tar++){

                int notTake = prev[tar];
                int take = 1e9;
                if(coins[idx] <= tar){
                    take = 1 + cur[tar - coins[idx]];
                }

                cur[tar] = min(take,notTake);
            }
            prev = cur;
        }

        int minCoins = prev[amount];
        return minCoins == 1e9 ? -1 : minCoins;
    }
};
