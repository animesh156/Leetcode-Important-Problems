// greedy approach O(n)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = accumulate(gas.begin(),gas.end(),0);
        int totalCost = accumulate(cost.begin(),cost.end(),0);

        if(totalGas < totalCost) return -1;
        int startIndex = 0;
        int curGas = 0;

        for(int i=0;i<gas.size();i++) {
            curGas += gas[i] - cost[i];
            if(curGas < 0) {
                curGas = 0;
                startIndex = i + 1;
            }
        }

        return startIndex;
    }
};

// brute force O(n^2)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for (int i = 0; i < n; i++) {
            int tank = gas[i] - cost[i];
            if (tank < 0) continue;

            int j = (i + 1) % n;
            while (j != i) {
                tank += gas[j] - cost[j];
                if (tank < 0) break;
                j = (j + 1) % n;
            }

            if (j == i) return i;
        }
        return -1;
    }
};
