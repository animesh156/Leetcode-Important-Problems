class Solution {
public:
    vector<int> findPrevSmaller(vector<int>& heights){
        int n = heights.size();
        vector<int> tmp(n);

        stack<int> st;

        for(int i=0;i<n;i++){

            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            tmp[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return tmp;
    }

     vector<int> findNextSmaller(vector<int>& heights){
        int n = heights.size();
        vector<int> tmp(n);

         stack<int> st;

        for(int i=n-1;i>=0;i--){

            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            tmp[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return tmp;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> left = findPrevSmaller(heights);
        vector<int> right = findNextSmaller(heights);

        int maxArea = 0;

        for(int i=0;i<n;i++){
            int width = right[i] - left[i] - 1;
             maxArea = max(maxArea, heights[i] * width);
        }

        return maxArea;
    }
};
