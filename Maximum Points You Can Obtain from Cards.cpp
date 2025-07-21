// sliding window
class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size();
        int i = 0, j = 0;

        // total sum of all cards
        int total = accumulate(card.begin(),card.end(),0);

        // edge case if k == n return total
        if(k == n) return total;

        int windowSize = (n - k);

        int minScore = total;
        int curScore = 0;

        while(j < n){
            // if current windo size is less expand
             if(j-i+1 < windowSize){
                 curScore += card[j];
                 j++;
             }
             else {
                curScore += card[j];
                // when window equal to required window-size
                minScore = min(minScore,curScore);
                
                //slide window
                curScore -= card[i];
                i++;
                j++;
             }
        }
        
       return total - minScore;
    }
};


// brute force O(k2)
class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size();
        int result = 0;
        for(int left = 0;left <= k;left++){
             int right = k - left;
             int sum = 0;

             for(int i=0;i<left;i++){
                sum += card[i];
             }

             for(int i=0;i<right;i++){
                sum += card[n - 1 - i];
             }

             result = max(result,sum);
        }

        return result;
    }
};
