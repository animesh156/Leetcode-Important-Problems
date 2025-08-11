 const int mod = 1e9 + 7;

class SegmentTree {
    int n;
    vector<int> tree;

    public:
    SegmentTree(vector<int> & v){
        n = v.size();
        tree.resize(4 * n);
        build(0,0,n-1,v);
    }

    void build(int node, int l, int r, vector<int> & arr){
        if(l == r){
            tree[node] = arr[l];
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * node + 1, l , mid, arr);
        build(2 * node + 2, mid + 1, r, arr);
        tree[node] = (1LL * tree[2*node + 1] * tree[2 * node + 2]) % mod;
    }

    long long query(int node, int l, int r, int ql, int qr){
        if(ql > r || qr < l) return 1;
        if(l >= ql && r <= qr) return tree[node];

        int mid = l + (r - l) / 2;

        long long left = query(2 * node + 1, l, mid, ql, qr);
        long long right = query(2 * node + 2, mid + 1, r, ql, qr);

        return (left * right) % mod;
    }
};


class Solution {
public:

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> tmp;
        for(int i=0;i<31;i++){
             if(n & (1 << i)) tmp.push_back(1 << i);
        }

        SegmentTree st(tmp);
      
        vector<int> res;

        for(auto it : queries){
           int l = it[0], r = it[1];
           long long pro = st.query(0,0,tmp.size()-1,l,r);
           res.push_back((int)pro);
        }

        return res;
    }
};
