#include <bits/stdc++.h>
using namespace std;

class FenWickTree
{
    vector<int> BIT;
    int n;

public:
    FenWickTree(int size)
    {
        n = size;
        BIT.resize(n + 1, 0);
    }

    // update arr[i] += delta
    void update(int i, int delta)
    {
        while (i <= n)
        {
            BIT[i] += delta;
            i = i + (i & (-i));
        }
    }

    //  prefixSum from 1 to i
    int getSum(int i)
    {
        int sum = 0;

        while (i > 0)
        {
            sum += BIT[i];
            i = i - (i & (-i));
        }

        return sum;
    }

    int rangeSum(int l, int r)
    {
        return getSum(r) - getSum(l - 1);
    }
};

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n + 1);

    FenWickTree ft(n);

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        ft.update(i, arr[i]);
    }

    cout << "before Update : " << endl;
    cout << ft.getSum(3) << endl;

    // ft.update(2, 4);

    // cout << "after Update : " << endl;
    // cout << ft.getSum(3) << endl;

    cout << "range sum: " << endl;

    cout << ft.rangeSum(2, 4);

    return 0;
}
