class RangeFreqQuery {
public:
   unordered_map<int, vector<int>> idxMap;
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0;i<arr.size();i++) {
            idxMap[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        if(idxMap.find(value) == idxMap.end()) return 0;
        vector<int>& indices = idxMap[value];

        auto lower = lower_bound(indices.begin(), indices.end(),left);
        auto upper = upper_bound(indices.begin(), indices.end(), right);

        return upper - lower;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
