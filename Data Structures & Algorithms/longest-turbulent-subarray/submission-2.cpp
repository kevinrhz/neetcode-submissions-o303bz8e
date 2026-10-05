class Solution {
    enum class State {
        None,
        Greater,
        Less
    };

public:
    int maxTurbulenceSize(const vector<int>& arr) {
        int l = 0, r = 1, res = 1;
        State prev = State::None;

        while (r < arr.size()) {
            if (arr[r - 1] > arr[r] && prev != State::Greater) {
                res = std::max(res, r - l + 1);
                ++r;
                prev = State::Greater;
            } else if (arr[r - 1] < arr[r] && prev != State::Less) {
                res = std::max(res, r - l + 1);
                ++r;
                prev = State::Less;
            } else {
                r = (arr[r] == arr[r - 1]) ? r + 1 : r;
                l = r - 1;
                prev = State::None;
            }
        }
        return res;
    }
};