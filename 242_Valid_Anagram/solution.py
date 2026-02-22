""";pre: Two arbitrary strings
;post: True or False
...in O(n + m) time and O(1) space
So in my solution, I wanted to avoid
any built in python that I knew wasn't O(1)
"""


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        a = [0] * 26  # How we instantiate lists full of stuff in python.
        for ch in s:
            a[ord(ch) % 26] = a[ord(ch) % 26] + 1

        for ch in t:
            a[ord(ch) % 26] = a[ord(ch) % 26] - 1
            if a[ord(ch) % 26] < 0:
                return False

        return True


"""Below is the fastest answer available on leetcode
    Using python
"""


class otherSolution:
    def isAnagram(self, s: str, t: str) -> bool:
        alphabets = "abcdefghijklmnopqrstuvwxyz"
        for item in alphabets:
            if s.count(item) != t.count(item):
                return False
        return True
