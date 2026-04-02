static const int _ = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        std::vector<int> res(n, 0);
        std::vector<int> stack;
        stack.reserve(n);

        for (int i = 0; i < n; ++i) {
            int current_temp = temperatures[i];
            int days = 1;

            while (!stack.empty() && current_temp > temperatures[stack.back()]) {
                int prev_index = stack.back();
                stack.pop_back();
                res[prev_index] += i - prev_index;
            }
            stack.push_back(i);
        }
        return res;
    }
};
