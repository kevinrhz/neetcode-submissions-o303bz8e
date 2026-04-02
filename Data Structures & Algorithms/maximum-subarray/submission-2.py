class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        current_sum, max_sub = 0, nums[0]

        for num in nums:
            if current_sum < 0:
                current_sum = 0
            current_sum += num
            max_sub = max(current_sum, max_sub)
        return max_sub