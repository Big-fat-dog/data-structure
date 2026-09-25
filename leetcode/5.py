class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if n < 2:
            return s
        
        start, maxLen = 0, 1
        
        def expand(left, right):
            while left >= 0 and right < n and s[left] == s[right]:
                left -= 1
                right += 1
            return right - left - 1  # 回文长度
        
        for i in range(n):
            len1 = expand(i, i)      # 奇数
            len2 = expand(i, i + 1)  # 偶数
            length = max(len1, len2)
            
            if length > maxLen:
                maxLen = length
                start = i - (length - 1) // 2
        
        return s[start:start + maxLen]