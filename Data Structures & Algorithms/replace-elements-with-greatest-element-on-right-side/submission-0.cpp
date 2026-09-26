class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max = -1;
        for (int i = arr.size() - 1; i >= 0; --i) {
            int newMax = std::max(max, arr[i]);
            arr[i] = max;
            max = newMax;
        }
        return arr;
    }
};