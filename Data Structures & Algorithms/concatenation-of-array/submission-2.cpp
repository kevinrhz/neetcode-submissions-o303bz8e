class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        std::vector<int> ans;
        ans.reserve(nums.size() * 2);

        for (const int num : nums) {
            ans.push_back(num);
        }
        for (const int num : nums) {
            ans.push_back(num);
        }
        return ans;
    }
};