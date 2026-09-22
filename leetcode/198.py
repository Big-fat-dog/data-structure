class Solution:
    def rob(self, nums: List[int]) -> int:
        #动态规划：维护dp数组,dp存储的是到当前索引偷到的最多的钱
        #可以将大问题抽象成小问题，比如偷前k家就是f(k)
        #关键在于偷不偷第i家值，偷就是加上nums[i]
        n = len(nums)
        if n==0:
            return 0
        if n==1:
            return nums[0]
        dp=[0]*n
        dp[0]=nums[0]
        dp[1]=max(nums[0],nums[1])
        for i in range(2,n):
            dp[i]=max(dp[i-1],nums[i]+dp[i-2])
        return dp[-1]
