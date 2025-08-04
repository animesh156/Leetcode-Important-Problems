class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res, prev;

        for(auto num : arr) {
             unordered_set<int> cur;
             cur.insert(num);

             for(auto it : prev) {
                cur.insert(it | num);
             }

             prev = cur;

             for(auto it : cur) {
                res.insert(it);
             }
        }

        return res.size();
    }
};
