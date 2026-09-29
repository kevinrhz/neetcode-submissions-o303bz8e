class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::vector<int> stk;
        for(const std::string& op : operations) {
            if (op[0] == '+') { // char comparison since guarunteed string is single char
                int val1 = stk[stk.size() - 1];
                int val2 = stk[stk.size() - 2];
                stk.push_back(val1 + val2);
            } else if (op[0] == 'D') {
                stk.push_back(stk.back() * 2);
            } else if (op[0] == 'C') {
                stk.pop_back();
            } else { // is digit
                stk.push_back(std::stoi(op));
            }
        }
        int sum = 0;
        for (const int num : stk) {
            sum += num;
        }
        return sum;
    }
};