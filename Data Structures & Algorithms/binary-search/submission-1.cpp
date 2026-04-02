class Solution {
public:
    int search(const vector<int>& nums, int target) {
        // 1. "Hey STL, do a highly-optimized binary search from the start pointer to the end pointer."
        // "Give me a pointer (it) to the first number >= target."
        std::vector<int>::const_iterator it = lower_bound(nums.begin(), nums.end(), target);

        // 2. "Did the pointer go out of bounds?" (it != nums.end())
        // 3. "If it's safe, read the value at that pointer. Does it exactly equal my target?" (*it == target)
        // 4. "If yes, subtract the start pointer to get the index. If no, return -1."
        return (it != nums.end() && *it == target) ? it - nums.begin() : -1;
    }
};
