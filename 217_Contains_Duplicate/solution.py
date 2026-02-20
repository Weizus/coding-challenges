""" The idea is to use a hash table. Check for collisions
    If there is a collision return true, else return false
"""
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        hash = dict()
        for num in nums:
            if (num in hash):
                return True
            hash[num] = None
        return False

""" The idea here is to use a set
    If the number of elements in the set is equal to the number of elements in the List
    Then we return false
"""
    def containsDuplicateSet(self, nums: List[int]) -> bool:
        return len(set(nums)) != len(nums)
