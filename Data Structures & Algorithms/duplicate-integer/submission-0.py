class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        map = dict()
        for n in nums:
            if n in map.keys():
                return True
            map[n] = 1
            
        return False
         