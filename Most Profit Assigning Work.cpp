// binary search soln O(m * logn)

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int maxProfit = 0;

        vector<pair<int,int>> jobs;

        for(int i=0;i<profit.size();i++) {
            jobs.push_back({difficulty[i],profit[i]});
        }

        sort(jobs.begin(),jobs.end());

        for(int i=1;i<profit.size();i++) {
            jobs[i].second = max(jobs[i].second,jobs[i-1].second);
        }

        for(auto w : worker) {
            int bestProfit = 0;
            int l = 0, r = jobs.size() - 1;

            while(l <= r) {
                int mid = l + (r-l) / 2;
                if(jobs[mid].first <= w) {
                    bestProfit = max(bestProfit,jobs[mid].second);
                    l = mid + 1;
                }
                else r = mid - 1;
            }

             maxProfit += bestProfit;
        }

        return maxProfit;
    }
};

// linear search Tc:- O(n^2)
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int maxProfit = 0;

        for(auto w : worker) {
            int bestProfit = 0;
            for(int i=difficulty.size()-1;i>=0;i--) {
                 if(difficulty[i] <= w) {
                     bestProfit = max(bestProfit,profit[i]);
                 }
            }

             maxProfit += bestProfit;
        }

        return maxProfit;
    }
};
