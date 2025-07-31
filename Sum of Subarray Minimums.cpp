class Solution {
public:

    vector<int> nle(vector<int>& arr) {
      int n = arr.size();
    vector<int> tmp(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        if(st.empty()) tmp[i] = n;
        else {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            tmp[i] = st.empty() ? n : st.top();
        }
        st.push(i);
    }
    return tmp;
    };

    vector<int> ple(vector<int>& arr) {
        int n = arr.size();
    stack<int> st;
    vector<int> tmp(n);
    for(int i=0;i<n;i++){
        if(st.empty()) tmp[i] = -1;
        else {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            tmp[i] = st.empty()?-1:st.top();
            
        }
        st.push(i);
    }
    return tmp;
    };


    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left = ple(arr);
        vector<int> right = nle(arr);
        const int mod = 1e9+7;

        int sum = 0;

        for(int i=0;i<n;i++) {
            long long l = i - left[i];
            long long r = right[i] - i;
            long long m = (l%mod * r%mod) % mod;
            sum = (sum + (arr[i] * m) % mod) % mod;
        }

        return sum;
    }
};
