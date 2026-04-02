class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_cache = {}
        for i in range(len(nums)):
            difference = target - nums[i]
            if difference in num_cache:
                return [num_cache[difference], i]
            else:
                num_cache[nums[i]] = i
        return []