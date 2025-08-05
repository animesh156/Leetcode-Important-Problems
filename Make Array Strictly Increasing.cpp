class Solution {
public:
    map<pair<int,int>,int> memo;

    int f(int ind,int prev,vector<int>& arr1, vector<int>& arr2) {
        if(ind == arr1.size()) return 0;
        if(memo.count({ind,prev})) return memo[{ind,prev}];

        int minOps = INT_MAX;
        if(arr1[ind] > prev){
            int keep = f(ind+1,arr1[ind], arr1, arr2);
            if(keep != INT_MAX) minOps = min(minOps,keep);
        }

        auto it = upper_bound(arr2.begin(),arr2.end(), prev);
              if(it != arr2.end()){
                int val = *it;
               int replace = f(ind+1,val,arr1,arr2);
                if (replace != INT_MAX) minOps = min(minOps, 1 + replace);
              }
                
        return memo[{ind,prev}] = minOps;
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        arr2.erase(unique(arr2.begin(),arr2.end()),arr2.end());
        int res = f(0,INT_MIN,arr1,arr2);
        return res == INT_MAX ? -1 : res;
    }
};
