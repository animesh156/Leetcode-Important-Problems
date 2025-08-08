class Solution {
public:
    void merge(vector<pair<int,int>> &arr, int left, int mid, int right, vector<int> &counts) {

        vector<pair<int, int>> tmp;

        int i = left, j = mid + 1;
        int rightCount = 0;

        while(i <= mid && j <= right){

            if(arr[j].first < arr[i].first){
                tmp.push_back(arr[j++]);
                rightCount++;
            }

            else {
                  counts[arr[i].second] += rightCount;
                  tmp.push_back(arr[i++]);
            }
        }

        while(i <= mid){
            counts[arr[i].second] += rightCount;
            tmp.push_back(arr[i++]);
        }

         while (j <= right) {
            tmp.push_back(arr[j++]);
        }

         for (int k = left; k <= right; ++k) {
            arr[k] = tmp[k - left];
        }
    }

    void mergeSort(vector<pair<int,int>> &valInd, int left, int right, vector<int> &counts) {
        if(left >= right) return;
        int mid = (left + right) / 2;
        mergeSort(valInd, left, mid, counts);
        mergeSort(valInd, mid + 1, right, counts);
        merge(valInd,left,mid,right,counts);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n,0);
        vector<pair<int,int>> valInd;

        for(int i=0;i<n;i++) valInd.push_back({nums[i],i});

        mergeSort(valInd, 0, n-1, counts);

        return counts;
    }
};
