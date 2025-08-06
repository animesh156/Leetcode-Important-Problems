class SegmentTree
{
public:
    vector<int> tree;
    int n;

    SegmentTree(vector<int> &arr)
    {
        n = arr.size();
        tree.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    void build(int node, int l, int r, vector<int> &arr)
    {
        if (l == r)
        {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node + 1, l, mid, arr);
        build(2 * node + 2, mid + 1, r, arr);
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    int query(int node, int l, int r,int val)
    {
        if(tree[node] < val) return -1;

        if(l == r) return l;

        int mid = (l + r) / 2;
        int left = query(2 * node + 1, l, mid,val);
        if(left != -1) return left;
       
        return query(2 * node + 2, mid + 1, r,val);
    }

    void update(int node, int l, int r, int idx)
    {
        if (l == r)
        {
            tree[node] = -1;
            return;
        }

        int mid = (l + r) / 2;
        if (idx <= mid)
        {
            update(2 * node + 1, l, mid, idx);
        }
        else
        {
            update(2 * node + 2, mid + 1, r, idx);
        }

        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }
};




class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        SegmentTree st(baskets);

        int unplaced = 0;

        for(auto fruit : fruits){
            int idx = st.query(0,0,n-1,fruit);
            if(idx == -1) unplaced++;
            else st.update(0,0,n-1,idx);
        }

        return unplaced;
    }
};
