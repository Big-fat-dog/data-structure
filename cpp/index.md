# 力扣热题100傻瓜式记录

## 简介

本文记录了一个傻狗二刷力扣时，抄写答案所总结的每题的技巧。俗称背诵。。。

仅涵盖简单与中等题，难题来了我就躺下给了！


- [力扣热题100傻瓜式记录](#力扣热题100傻瓜式记录)
  - [简介](#简介)
  - [哈希](#哈希)
    - [1.两数之和](#1两数之和)
    - [2.字母异位分词](#2字母异位分词)
    - [3.最长连续序列](#3最长连续序列)
  - [双指针](#双指针)
    - [4.移动零](#4移动零)
    - [5.盛水最多的容器](#5盛水最多的容器)
    - [6.三数之和](#6三数之和)
    - [7.接雨水](#7接雨水)
  - [滑动窗口](#滑动窗口)
    - [7.无重复的最长子串](#7无重复的最长子串)
    - [8.找到字符串中所有字母异位词](#8找到字符串中所有字母异位词)
  - [子串](#子串)
    - [9.和为k的子数组](#9和为k的子数组)
    - [10.滑动窗口最大值](#10滑动窗口最大值)
    - [11.最小覆盖子串](#11最小覆盖子串)
  - [普通数组](#普通数组)
    - [12.最大子数组和](#12最大子数组和)
    - [13.合并区间](#13合并区间)
    - [14.轮转数组](#14轮转数组)
    - [15.除了自身以外数组的乘积](#15除了自身以外数组的乘积)
    - [16.缺失的第一个正数](#16缺失的第一个正数)
  - [矩阵](#矩阵)
    - [17.矩阵置零](#17矩阵置零)
    - [18.螺旋矩阵](#18螺旋矩阵)
    - [19.旋转图像](#19旋转图像)
    - [20.搜索二维矩阵ll](#20搜索二维矩阵ll)
  - [链表](#链表)
    - [21.相交链表](#21相交链表)
    - [22.反转链表](#22反转链表)
    - [23.回文链表](#23回文链表)
    - [24.环形链表](#24环形链表)
    - [25.环形链表||](#25环形链表)
    - [26.合并两个有序链表](#26合并两个有序链表)
    - [27.两数相加](#27两数相加)
    - [28.删除链表的倒数第n个节点](#28删除链表的倒数第n个节点)
    - [29.两两交换链表中的节点](#29两两交换链表中的节点)
    - [30.K 个一组翻转链表](#30k-个一组翻转链表)
    - [31.随机链表的复制](#31随机链表的复制)
    - [32.排序链表](#32排序链表)
    - [33.合并k个升序链表](#33合并k个升序链表)
    - [34.LRU缓存](#34lru缓存)
  - [二叉树](#二叉树)
    - [35、中序遍历](#35中序遍历)
    - [36、二叉树最大深度](#36二叉树最大深度)
    - [37、翻转二叉树](#37翻转二叉树)
    - [38、对称二叉树](#38对称二叉树)
    - [39.二叉树的直径](#39二叉树的直径)
    - [40.二叉树的层序遍历](#40二叉树的层序遍历)
    - [41.将有序数组转换成平衡二叉树](#41将有序数组转换成平衡二叉树)
    - [42.验证二叉搜搜书](#42验证二叉搜搜书)
    - [43.二叉搜索树第k个值](#43二叉搜索树第k个值)
    - [44.二叉树的右视图](#44二叉树的右视图)
    - [45.二叉树展开为链表](#45二叉树展开为链表)
    - [46.从前序与中序遍历序列构造二叉树](#46从前序与中序遍历序列构造二叉树)
    - [47.路径总和lll](#47路径总和lll)
    - [48.二叉树的最近公共祖先节点](#48二叉树的最近公共祖先节点)
    - [49.二叉树的最大路径和](#49二叉树的最大路径和)
  - [图论](#图论)
    - [50.岛屿数量](#50岛屿数量)
    - [51.腐烂的橘子](#51腐烂的橘子)
  - [回溯](#回溯)
    - [52.全排列](#52全排列)
    - [53.子集](#53子集)
    - [54.电话号码的数字组合](#54电话号码的数字组合)
    - [55.组合总和](#55组合总和)
    - [56.括号生成](#56括号生成)
    - [57.单词搜索](#57单词搜索)
    - [58.分割字符串](#58分割字符串)
  - [二分查找](#二分查找)
    - [59.搜索插入位置](#59搜索插入位置)
    - [60.搜索二维矩阵](#60搜索二维矩阵)
    - [61.在排序数组中查找元素的第一个和最后一个位置](#61在排序数组中查找元素的第一个和最后一个位置)
    - [62.搜索旋转数组](#62搜索旋转数组)
    - [63.寻找旋转排序数组中的最小值](#63寻找旋转排序数组中的最小值)
  - [栈](#栈)
    - [64.有效的括号](#64有效的括号)
    - [65.最小栈](#65最小栈)
    - [66.字符串解码](#66字符串解码)
    - [67.每日温度](#67每日温度)
    - [68.柱状图中的最大矩形](#68柱状图中的最大矩形)
  - [堆](#堆)
    - [69.数组中的第K个最大元素](#69数组中的第k个最大元素)
    - [70.前k个高频元素](#70前k个高频元素)
  - [贪心算法](#贪心算法)
    - [71.股票买卖最佳时机](#71股票买卖最佳时机)
    - [72.跳跃游戏](#72跳跃游戏)
    - [73.跳跃游戏ll](#73跳跃游戏ll)
    - [74.划分字母区间](#74划分字母区间)
  - [动态规划](#动态规划)
    - [75.爬楼梯](#75爬楼梯)
    - [76.杨辉三角](#76杨辉三角)
    - [77.打家劫舍](#77打家劫舍)
    - [78.完全平方数](#78完全平方数)
    - [79.零钱兑换](#79零钱兑换)
    - [80.单词拆分](#80单词拆分)
    - [81.最长递增子序列](#81最长递增子序列)
    - [82.乘积最大子数组](#82乘积最大子数组)
    - [83.分割等和子集](#83分割等和子集)
    - [84.最长有效括号](#84最长有效括号)
  - [多维动态规划](#多维动态规划)
    - [85.不同路径](#85不同路径)
    - [86.最小路径和](#86最小路径和)
  - [技巧](#技巧)
    - [87.只出现一次的数](#87只出现一次的数)
    - [88.多数元素](#88多数元素)


## 哈希

核心思想：利用哈希表或集合，把重复查找从反复遍历转化为快速查询。

记忆口诀：找补数用哈希，数频次用计数，按特征分组用键，连续序列找起点。

| 具体方法                    | 对应题号与题目   | 关键思路                                               |
| --------------------------- | ---------------- | ------------------------------------------------------ |
| 哈希表边查边存              | 1 两数之和       | 查找 `target - num`，找不到再存当前数及其下标          |
| 哈希计数 + 元组作为键       | 2 字母异位词分组 | 统计 26 个字母的出现次数，将计数数组转为元组作为分组键 |
| 集合去重 + 连续序列起点判断 | 3 最长连续序列   | 只从不存在前驱 `num-1` 的数字开始向后遍历              |

### 1.两数之和

哈希表+边存边查，这样就不会用到同一个位置的数字了。

```py
class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        #边存边查，就不会导致用到同一个位置的了
        mmp={}
        for i,num in enumerate(nums):
            tarr = target-num
            if tarr in mmp:
                return [mmp[tarr],i]
            mmp[num] = i
        return []
```

### 2.字母异位分词

哈希表+unicode存储字母

```py
class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        mmp = {}
        for str in strs:
            count = [0]*26
            for word in str:
                tmp = ord(word)-ord('a')
                count[tmp]+=1
            key = tuple(count)
            if key not in mmp:#注意这个初始化
                mmp[key] = []
            mmp[key].append(str)
        result = list(mmp.values())#这个取所有值
        return result

```

或者对字符串进行排序

```py
class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        mapping={}
        for s in strs:
            sort_s=''.join(sorted(s))
            if sort_s not in mapping:
                mapping[sort_s]=[]
            mapping[sort_s].append(s)
        return list(mapping.values())
```



### 3.最长连续序列

集合去重+查看更新比当前小1的数来锚定位置

```py
class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        my_nums = set(nums)
        max_len = 0
        for num in my_nums:
            if num-1 not in my_nums:
                cur=num
                cur_len=1
                while cur+1 in my_nums:
                    cur+=1
                    cur_len+=1
                max_len=max(max_len,cur_len)
        return max_len

```

## 双指针

核心思想：使用两个位置或两个移动速度不同的指针，减少重复遍历。

记忆口诀：同向处理数组，相向缩小范围，排序后找组合，双端维护边界。

| 具体方法                       | 对应题号与题目   | 关键思路                                           |
| ------------------------------ | ---------------- | -------------------------------------------------- |
| 快慢指针 + 原地交换            | 4 移动零         | 快指针寻找非零元素，慢指针维护非零元素的写入位置   |
| 左右双指针 + 贪心移动          | 5 盛水最多的容器 | 计算当前面积，每次移动高度较小的一侧               |
| 排序 + 固定一个数 + 左右双指针 | 6 三数之和       | 固定第一个数，根据总和移动左右指针，同时去重和剪枝 |
| 左右双指针 + 两侧最大值        | 7 接雨水         | 维护左右最大高度，处理能够确定积水量的一侧         |

### 4.移动零

快慢指针+如果快指针遇到零了就交换值+最后填充覆盖0

```py
class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n=len(nums)
        slow=0
        for fast in range(n):
            if nums[fast]!=0:
                nums[fast],nums[slow]=nums[slow],nums[fast]
                slow+=1
        for i in range(slow,n):
            nums[i]=0
        
```

### 5.盛水最多的容器

左右指针+面积公式-长*宽（宽是每次固定，长则要从高里面选较矮的）+更新高度（哪边矮就移动哪边的指针）

```py
class Solution:
    def maxArea(self, height: list[int]) -> int:
        maxsize=0
        left=0
        n=len(height)
        right=n-1
        while left<right:
            length = right-left
            high = min(height[left],height[right])
            area = length*high
            maxsize=max(area,maxsize)
            if height[left]<height[right]:
                left+=1
            else:
                right-=1
        return maxsize
```

### 6.三数之和

排序-固定第一个数-左右双指针-去重（与后一个数重复就移动指针）-剪枝（排序后如果当前大于零则后面都大于零，直接break）

```py
class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        #排序-固定第一个数-左右双指针-去重-剪枝  
        nums.sort()
        n=len(nums)
        result=[]

        for i in range(n-2):
            #去重
            if i>0 and nums[i] == nums[i-1]:
                continue
            #剪枝
            if nums[i]>0:
                break
            left =i+1
            right=n-1
            while left<right:
                total = nums[left]+nums[i]+nums[right]
                if total == 0:
                    result.append([nums[i],nums[left],nums[right]])
                    while left<right and nums[left] == nums[left+1]:
                        #跳过左边重复的
                        left+=1
                    while left<right and nums[right] == nums[right-1]:
                        right-=1
                    left+=1
                    right-=1
                elif total<0:
                    left+=1
                else:
                    right-=1
        return result

```

### 7.接雨水

```py
class Solution:
    def trap(self, height: list[int]) -> int:
        n=len(height)
        if n==0:
            return 0
        left=0
        right=n-1
        leftmax=rightmax=0
        ans=0

        while left<right:
            leftmax=max(leftmax,height[left])
            rightmax=max(rightmax,height[right])

            if leftmax<rightmax:
                ans+=leftmax-height[left]
                left+=1
            else:
                ans+=rightmax-height[right]
                right-=1

        return ans
```



## 滑动窗口

核心思想：维护一个连续区间，通过移动左右边界来更新窗口信息，避免每次从头计算。

| 具体方法                         | 对应题号与题目                          | 关键思路                                             |
| -------------------------------- | --------------------------------------- | ---------------------------------------------------- |
| 可变长窗口 + 哈希表记录最近位置  | 7（原文编号）无重复的最长子串           | 出现重复字符时，将左边界移动到上次出现位置的下一位   |
| 定长窗口 + 字符频次统计          | 8（原文编号）找到字符串中所有字母异位词 | 维护长度为 `len(p)` 的窗口，通过字符计数判断是否匹配 |
| 可变长窗口 + `need/window/valid` | 11（原文编号）最小覆盖子串              | 满足覆盖条件时不断收缩左边界，寻找最短合法窗口       |

### 7.无重复的最长子串

哈希存储right跑过的字母位置+先存储当前长度+如果right跑过的重复了就更新左指针

```py
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_pos={}
        left=0
        max_len=0

        for right,ch in enumerate(s):
            if ch in last_pos and last_pos[ch]>=left:
                left=last_pos[ch]+1
            last_pos[ch]=right
            max_len=max(max_len,right-left+1)
        return max_len
```

### 8.找到字符串中所有字母异位词

滑动窗口+哈希表统计+valid优化计数

```py
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        #定长滑动窗口+字符串计数
        m,n=len(s),len(p)
        if m<n:
            return []
        window={}
        need={}
        ans=[]
        left=0
        valid=0
        for ch in p:
            need[ch]=need.get(ch,0)+1
        
        for right in range(m):
            ch=s[right]
            if ch in need:
                window[ch]=window.get(ch,0)+1
                if window[ch]==need[ch]:
                    valid+=1
            
            if right-left+1==n:
                if valid==len(need):
                    ans.append(left)
                lfch=s[left]
                if lfch in need:
                    if window[lfch]==need[lfch]:
                        valid-=1
                    window[lfch]-=1
                left+=1
        return ans
                
```

## 子串

核心思想：利用前缀和、哈希表或单调队列，解决连续子数组的统计、区间查询和窗口最值问题。

记忆口诀：子数组求和想前缀和，窗口极值想单调队列，覆盖问题想双哈希表 + 滑动窗口。

| 具体方法                  | 对应题号与题目    | 关键思路                                                     |
| ------------------------- | ----------------- | ------------------------------------------------------------ |
| 前缀和 + 哈希表统计次数   | 9 和为 K 的子数组 | 当前前缀和为 `prefix`，查找之前出现过多少次 `prefix-k`，先查再存 |
| 单调递减双端队列          | 10 滑动窗口最大值 | 队列存下标，队首是最大值下标，队尾删除不可能成为最大值的元素 |
| 双哈希表 + 可变长滑动窗口 | 11 最小覆盖子串   | 统计目标字符需求，满足全部需求后收缩左边界，更新最短答案     |

### 9.和为k的子数组

前缀和+哈希表存次数

```py
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        #前缀和加上哈希表统计次数。但是先查后存，因为要查的是之前的前缀和，不能包含本次
        count={0:1}
        ans=0
        prefix=0
 
        for num in nums:
            prefix+=num
            ans+=count.get(prefix-k,0)
            count[prefix]=count.get(prefix,0)+1
            
        return ans
```

### 10.滑动窗口最大值

双端队列+递减队列+while维护

```py
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        dp=deque()
        result=[]
        n=len(nums)
        for i in range(n):
            while dp and nums[dp[-1]]<=nums[i]:
                dp.pop()

            dp.append(i)

            if dp[0]<=i-k:
                dp.popleft()

            if i>=k-1:
                result.append(nums[dp[0]])
        return result
```

### 11.最小覆盖子串

两个哈希表统计+维护左边界+滑动窗口

```py
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(s)<len(t):
            return ""
        
        need={}
        for i in t:
            need[i] = need.get(i, 0) + 1
        window={}
        length = float('inf')
        start=0
        left=0
        right=0
        valid=0

        while right < len(s):
            c=s[right]
            right+=1
            if c in need:
                window[c] = window.get(c, 0) + 1
                if window[c] == need[c]:
                    valid+=1
            while valid==len(need):
                # 更新最小覆盖子串（只在更短时更新）
                if right - left < length:
                    start = left
                    length = right - left
            
                d=s[left]
                if d in need:
                    if window[d] == need[d]:
                        valid-=1
                    window[d]-=1
                left+=1
        if length == float('inf'):
            return ''
        return s[start:start+length]
```

## 普通数组

核心思想：通过动态规划、排序、区间合并、原地变换以及前后缀信息来处理数组。

| 具体方法            | 对应题号与题目            | 关键思路                                                     |
| ------------------- | ------------------------- | ------------------------------------------------------------ |
| 动态规划 + 状态转移 | 12 最大子数组和           | `dp = max(dp + num, num)`，决定接上前面的子数组还是重新开始  |
| 排序 + 区间合并     | 13 合并区间               | 按区间左端点排序，判断当前区间与下一区间是否重叠             |
| 三次翻转 + 取模     | 14 轮转数组               | 先整体翻转，再分别翻转两段，`k %= n`                         |
| 前缀积 + 后缀积     | 15 除了自身以外数组的乘积 | 每个位置的结果等于其左侧乘积乘以右侧乘积                     |
| 原地交换 + 索引映射 | 16 缺失的第一个正数       | 将值 `x` 尽可能放到下标 `x-1`，再寻找第一个位置和值不对应的下标 |

### 12.最大子数组和

动态规划+比较

```py
class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        dp=nums[0]
        max_nums=nums[0]
        
        for num in nums[1:]:
            dp=max(dp+num,num)
            max_nums=max(max_nums,dp)
        return max_nums
```

### 13.合并区间

排序+判断+注意最后一个要手动给他塞进去

```py
class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        #排序+前后区间对比
        intervals.sort(key=lambda x:x[0])
        cur=intervals[0]
        res=[]
        
        for i in range(1,len(intervals)):
            nxt=intervals[i]
            if cur[1]>=nxt[0]:
                cur[1]=max(cur[1],nxt[1])
            else:
                res.append(cur)
                cur=nxt
        res.append(cur)
        return res
```

### 14.轮转数组

三次翻转+取模防止溢出

```py
class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        #三次翻转+取模防止溢出
        n=len(nums)
        k=k%n

        def reverse(left,right):
            while left<right:
                nums[left],nums[right]=nums[right],nums[left]
                left+=1
                right-=1
        
        reverse(0,n-1)
        reverse(0,k-1)
        reverse(k,n-1)
```

### 15.除了自身以外数组的乘积

前缀积+后缀积+合并

```py
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        #前缀积+后缀及
        n=len(nums)
        prefix=[1]*n
        suffix=[1]*n
        res=[1]*n

        #前缀
        for i in range(1,n):
            prefix[i]=prefix[i-1]*nums[i-1]

        #后缀
        for i in range(n-2,-1,-1):
            suffix[i]=suffix[i+1]*nums[i+1]

        #合并
        for i in range(n):
            res[i]=prefix[i]*suffix[i]
        
        return res
```

### 16.缺失的第一个正数

将nums[i]放到i+1的位置，并且要让nums[i]处于[1,n]范围内，如果都在则返回n+1

```py
class Solution:
    def firstMissingPositive(self, nums: list[int]) -> int:
        #把nums[i]放到i+1的位置
        n=len(nums)
        
        for i in range(n):
            while 1<=nums[i]<=n and nums[i]!=nums[nums[i]-1]:
                cor_id=nums[i]-1
                nums[i],nums[cor_id]=nums[cor_id],nums[i]
        
        for i in range(n):
            if nums[i]!=i+1:
                return i+1
                
        return n+1
                
       
```

## 矩阵

核心思想：明确行列边界、利用矩阵的几何结构，或者将部分行列作为辅助标记。

| 具体方法            | 对应题号与题目     | 关键思路                                                     |
| ------------------- | ------------------ | ------------------------------------------------------------ |
| 首行首列原地标记    | 17 矩阵置零        | 利用第一行和第一列标记哪些行列需要清零，并单独记录首行、首列原本是否含零 |
| 四边界收缩          | 18 螺旋矩阵        | 用 `top/bottom/left/right` 控制遍历边界，按顺时针逐层收缩    |
| 矩阵转置 + 左右翻转 | 19 旋转图像        | 先沿主对角线转置，再对每一行左右翻转                         |
| 从右上角开始搜索    | 20 搜索二维矩阵 II | 当前值大于目标就向左，小于目标就向下，每次排除一行或一列     |

### 17.矩阵置零

将第一行和第一列作为标记，然后遍历

```py
class Solution:
    def setZeroes(self, matrix: list[list[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        #用第一行和第一列做标记
        m,n=len(matrix),len(matrix[0])
        
        row_zero=any(matrix[0][j]==0 for j in range(n))
        col_zero=any(matrix[i][0]==0 for i in range(m))
        
        #遍历，打标记
        for i in range(m):
            for j in range(n):
                if matrix[i][j]==0:
                    matrix[0][j]=0
                    matrix[i][0]=0
                    
         #根据标记制空对应的行列           
        for i in range(1,m):
            for j in range(1,n):
                if matrix[i][0]==0 or matrix[0][j]==0:
                    matrix[i][j]=0
                    
        if row_zero:
            for i in range(n):
                matrix[0][i]=0
                
        if col_zero:
            for j in range(m):
                matrix[j][0]=0
```

### 18.螺旋矩阵

设置上下左右边界，注意循环条件

```py
class Solution:
    def spiralOrder(self, matrix: list[list[int]]) -> list[int]:
        m,n=len(matrix),len(matrix[0])
        left=0
        right=n-1
        top=0
        bottom=m-1
        res=[]
        
        while top<=bottom and left<=right:
            for j in range(left,right+1):
                res.append(matrix[top][j])
            top+=1
                
            for j in range(top,bottom+1):
                res.append(matrix[j][right])
            right-=1
            
            if top<=bottom:
                for j in range(right,left-1,-1):
                    res.append(matrix[bottom][j])
                bottom-=1
            if left<=right:
                for j in range(bottom,top-1,-1):
                    res.append(matrix[j][left])
                left+=1
            
            
        return res

```

### 19.旋转图像

转置（注意是沿着主对角线）+翻转

```py
class Solution:
    def rotate(self, matrix: list[list[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        #转置+左右翻转
        n=len(matrix)
        for i in range(n):
            for j in range(i+1,n):#沿着主对角线对称翻转，如果从零开始则又会转回来
                matrix[i][j],matrix[j][i]=matrix[j][i],matrix[i][j]
                
        for i in range(n):
            for j in range(n//2):
                matrix[i][n-1-j],matrix[i][j]=matrix[i][j],matrix[i][n-1-j]
                
```

### 20.搜索二维矩阵ll

以右上角为起点缩减行列。

```py
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        #选取右上角作为起点，这样能明确往下还是往左。每次能缩减一行一列
        m,n=len(matrix),len(matrix[0])
        i=0
        j=n-1
        while i<m and j>=0:
            if matrix[i][j]==target:
                return True
            elif matrix[i][j]>target:
                j-=1
            else:
                i+=1
        return False
```

## 链表

| 具体方法                    | 对应题号与题目               | 关键思路                                                     |
| --------------------------- | ---------------------------- | ------------------------------------------------------------ |
| 双指针交替遍历              | 21 相交链表                  | 两个指针分别遍历两条链表，走完后切换到另一条链表的头部       |
| 三指针迭代反转              | 22 反转链表                  | 使用 `prev/cur/nxt` 保存前驱、当前节点和后继节点，逐个反转指向 |
| 快慢指针找中点 + 反转后半段 | 23 回文链表                  | 找到中点，反转后半段，再逐个比较两侧节点                     |
| 快慢指针判环                | 24 环形链表                  | 快指针每次走两步，慢指针每次走一步，相遇说明有环             |
| 快慢指针定位环入口          | 25 环形链表 II               | 先找相遇点，再让一个指针回到头节点，两指针同速前进，第二次相遇即入口 |
| 双指针 + 虚拟头节点         | 26 合并两个有序链表          | 比较两个当前节点，把较小节点接到结果链表末尾，最后拼接剩余部分 |
| 双指针 + 进位计算           | 27 两数相加                  | 逐位相加，使用 `total % 10` 取得当前位、`total // 10` 取得进位 |
| 快慢指针 + 虚拟头节点       | 28 删除链表的倒数第 N 个节点 | 快指针先走 N 步，再同步移动，使慢指针停在待删除节点的前一个位置 |
| 虚拟头节点 + 局部指针重连   | 29 两两交换链表中的节点      | 每次重连两个节点及前驱节点，不交换节点值                     |
| 分组反转 + 分段连接         | 30 K 个一组翻转链表          | 找到每组第 K 个节点，反转当前组，再连接前后两组              |

| 具体方法          | 对应题号与题目       | 关键思路                                                     |
| ----------------- | -------------------- | ------------------------------------------------------------ |
| 哈希表映射节点    | 31 随机链表的复制    | 第一次创建每个原节点对应的新节点，第二次连接新节点的 `next` 和 `random` |
| 归并排序 + 分治   | 32 排序链表          | 找中点、断开链表、递归排序两段，再合并两个有序链表           |
| 分治 + 两两合并   | 33 合并 K 个升序链表 | 将链表数组分成两半，递归合并，再把两部分结果合并             |
| 哈希表 + 双向链表 | 34 LRU 缓存          | 哈希表实现快速定位，双向链表维护最近使用顺序，超容量时删除尾部节点 |

### 21.相交链表

两个指针分别从两个头走+走完一个去另一条，如果相遇则说明香蕉

```py
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        temp1=headA
        temp2=headB
        
        while temp1!=temp2:
            temp1=temp1.next if temp1 else headB
            temp2=temp2.next if temp2 else headA
        return temp1
```

### 22.反转链表

定义两个指针，prev以及cur，并进行while循环，最后返回prev

```py
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode | None) -> ListNode | None:
        prev=None
        cur=head
        while cur!=None:
            nxt=cur.next
            cur.next=prev
            prev=cur
            cur=nxt
        return prev
```

### 23.回文链表

快慢指针找中点+反转后半部分

```py
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        #快慢指针找中点+反转后半部分
        if head.next is None:
            return True
        slow=fast=head

        while fast and fast.next:
            slow=slow.next
            fast=fast.next.next

        prev=None
        cur = slow
        while cur!= None:
            nxt=cur.next
            cur.next=prev
            prev=cur
            cur=nxt

        left=head
        right=prev

        while right!=None:
            if left.val!=right.val:
                return False
            left=left.next
            right=right.next
        return True

```

### 24.环形链表

操场跑圈：快的跑两圈一定能追上慢的

```py
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        #操场跑圈：快的跑两圈一定能追上慢的
        slow=fast=head

        while fast and fast.next:
            slow=slow.next
            fast=fast.next.next
            if fast==slow:
                return True
        return False
```

### 25.环形链表||

快慢指针找相遇点+让一个指针回到head再以相同速度运动，相遇即返回+用while else

```py
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        #这题要返回相遇点的值而不是简单的判断相不相遇
        #快慢指针找相遇点+让一个指针回到head再以相同速度运动，相遇即返回
        fast=slow=head
        
        while fast and fast.next:
            slow=slow.next
            fast=fast.next.next
            if fast==slow:
                break
        else:
            return None

        ptr1=head
        ptr2=slow
        while ptr1!=ptr2:
            ptr1=ptr1.next
            ptr2=ptr2.next
        return ptr1
```

### 26.合并两个有序链表

双指针比对+虚拟头+拼接剩余部分

```py
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: ListNode | None, list2: ListNode | None) -> ListNode | None:
        #虚拟头+双指针
        dummy=ListNode(0)
        cur = dummy

        while list1 and list2:
            if list1.val<=list2.val:
                cur.next=list1
                list1=list1.next
            else:
                cur.next=list2
                list2=list2.next
            cur=cur.next
        
        #拼上剩下的
        cur.next = list1 if list1 else list2
        return dummy.next
        
```

### 27.两数相加

数学运算标记进位（//10)+取当前位置的值(%10)

```py
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode | None, l2: ListNode | None) -> ListNode | None:
        #一个标记用于进位（//10）+获取当前值（total%10）
        dummy = ListNode(0)
        cur = dummy
        carry=0

        while l1 or l2 or carry:
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0
            #算出当前位的值
            total = v1+v2+carry        
            carry = total//10
            #取完进位之后的值
            cur.next = ListNode(total%10)
            cur = cur.next
            if l1:
                l1=l1.next
            if l2:
                l2=l2.next

        return dummy.next


```

### 28.删除链表的倒数第n个节点

快慢指针：快指针先走n步然后快慢指针同时走，快指针走到none，慢指针最后会停在n+1的位置。

```py
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode | None, n: int) -> ListNode | None:
        #快慢指针：快指针先走n步然后快慢指针同时走，快指针走到none，慢指针最后会停在n+1的位置。
        dummy=ListNode(0)
        fast=slow=dummy
        dummy.next=head

        #fast先走n步
        for _ in range(n):
            fast=fast.next
        
        #走到none前，那此时slow也就在倒数n+1的位置
        while fast.next:
            slow=slow.next
            fast=fast.next
        
        slow.next=slow.next.next
        return dummy.next
```

### 29.两两交换链表中的节点

虚拟头节点+反转

```py
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: ListNode | None) -> ListNode | None:
        dummy=ListNode(0)
        dummy.next=head
        prev=dummy
        
        while prev.next and prev.next.next:
            first=prev.next
            second=first.next
            nxt=second.next
            
            first.next=nxt
            second.next=first
            prev.next=second
            
            prev=first
            
        return dummy.next
```

### 30.K 个一组翻转链表

流程：虚拟头+分段遍历+判断+反转+链接

```py
class Solution:
    def reverseKGroup(self, head, k):
        dummy = ListNode(0)
        dummy.next = head
        groupPrev = dummy

        while True:
            # 找这一组的第 k 个节点
            kth = self.getKth(groupPrev, k)
            if not kth:
                break

            groupNext = kth.next

            # 翻转 groupPrev.next 到 kth
            new_head, new_tail = self.reverse(groupPrev.next, kth)

            # 连接
            groupPrev.next = new_head
            new_tail.next = groupNext
            groupPrev = new_tail

        return dummy.next

    def getKth(self, node, k):
        """从 node 往后走 k 步，返回第 k 个节点，走不到返回 None"""
        cur = node
        for _ in range(k):
            cur = cur.next
            if not cur:
                return None
        return cur

    def reverse(self, head, tail):
        """翻转 head 到 tail 之间的链表（包含 tail），返回 (新头, 新尾)"""
        prev = None
        cur = head
        while cur != tail:
            nxt = cur.next
            cur.next = prev
            prev = cur
            cur = nxt
        # 处理 tail
        cur.next = prev
        return tail, head   # 新头是 tail，新尾是 head
```

### 31.随机链表的复制

哈希表键值都存节点+两次遍历原链表

```py
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None
        #哈希表记录，以节点为键值对+两次便利原链表
        mapping={}
        cur=head
        while cur:
            mapping[cur]=Node(cur.val)
            cur=cur.next
            
        cur=head
        while cur:
            if cur.next:
                mapping[cur].next=mapping[cur.next]
            if cur.random:
                mapping[cur].random=mapping[cur.random]
            cur=cur.next
        return mapping[head]
               
        
```

### 32.排序链表

归并排序+分治

找中点+断开+递归排序+合并

```py
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        #归并排序+分治
        #链表归并的优势：合并两个有序链表时，只需调整指针，不需要额外空间。
        #找中点+断开+递归排序+合并
        if not head or not head.next:
            return head
        slow,fast=head,head.next
        while fast and fast.next:
            slow=slow.next
            fast=fast.next.next
            
         
        mid=slow.next
        slow.next=None
        
        left=self.sortList(head)
        right=self.sortList(mid)
        
        return self.merge(left,right)
        
    def merge(self,l1,l2):
        dummy=ListNode(0)
        cur=dummy
        while l1 and l2:
            if l1.val<=l2.val:
                cur.next=l1
                l1=l1.next
            else:
                cur.next=l2
                l2=l2.next
                
            cur=cur.next
            
        cur.next=l1 if l1 else l2
        return dummy.next
```

### 33.合并k个升序链表

分治合并+不需要断开，因为已经断好了+传原始数组以提供索引

```py
class Solution:
    def mergeKLists(self, lists):
        if not lists:
            return None
        return self._merge(lists, 0, len(lists) - 1)

    def _merge(self, lists, left, right):
        if left == right:
            return lists[left]
        mid = (left + right) // 2
        l1 = self._merge(lists, left, mid)
        l2 = self._merge(lists, mid + 1, right)
        return self.mergeTwo(l1, l2)

    def mergeTwo(self, l1, l2):
        dummy = ListNode(0)
        cur = dummy
        while l1 and l2:
            if l1.val <= l2.val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
            cur = cur.next
        cur.next = l1 if l1 else l2
        return dummy.next
```

### 34.LRU缓存

双向链表+哈希表存节点+额外定义三个函数用于存储与删除与移动表头

```py
class Node:
    def __init__(self,key=0,value=0):
        self.key=key
        self.value=value
        self.prev=None
        self.next=None
class LRUCache:
    #哈希表做缓存+双向链表+烧饼首尾节点
    #额外实现删除与添加存放到表头的功能以及移动到头的功能

    def __init__(self, capacity: int):
        self.capacity=capacity
        self.cache={}
        
        self.head=Node()
        self.tail=Node()
        self.head.next=self.tail
        self.tail.prev=self.head

    def remove(self,node):
        node.prev.next=node.next
        node.next.prev=node.prev

    def add_to_head(self,node):
        node.next=self.head.next
        node.prev=self.head
        self.head.next.prev=node
        self.head.next=node

    def move_to_head(self,node):
        self.remove(node)
        self.add_to_head(node)

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        node=self.cache[key]
        self.move_to_head(node)
        return node.value

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            node = self.cache[key]
            node.value = value              # 改节点的值
            self.move_to_head(node)         # 移到头部
        else:
            node = Node(key,value)
            self.cache[key]=node
            self.add_to_head(node)

        #超过容量就删掉尾部
        if len(self.cache)>self.capacity:
            tail_node=self.tail.prev
            self.remove(tail_node)
            del self.cache[tail_node.key]


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```

## 二叉树

| 具体方法                | 对应题号与题目                | 关键思路                                                     |
| ----------------------- | ----------------------------- | ------------------------------------------------------------ |
| 中序 DFS：左、根、右    | 35 中序遍历                   | 递归遍历左子树，记录当前节点，再遍历右子树                   |
| 递归 + 左右子树取最大值 | 36 二叉树最大深度             | 空节点深度为 0，当前深度为左右子树最大深度加 1               |
| 前序遍历 + 交换左右子树 | 37 翻转二叉树                 | 先交换当前节点的左右子树，再递归处理子树                     |
| 递归交叉比较            | 38 对称二叉树                 | 比较左子树的左节点与右子树的右节点，以及左子树的右节点与右子树的左节点 |
| 后序 DFS + 全局答案更新 | 39 二叉树的直径               | 先计算左右子树深度，再用左右深度之和更新直径                 |
| BFS + 队列分层          | 40 二叉树的层序遍历           | 每轮固定当前队列长度，遍历完这一层后再处理下一层             |
| 分治 + 中间位置建根     | 41 将有序数组转换成平衡二叉树 | 每次选取区间中点作为根节点，递归构造左右子树                 |

层序遍历

| 具体方法                      | 对应题号与题目                    | 关键思路                                               |
| ----------------------------- | --------------------------------- | ------------------------------------------------------ |
| 中序遍历 + 前驱值比较         | 42 验证二叉搜索树                 | BST 的中序遍历必须严格递增                             |
| 中序遍历 + 计数 + 剪枝        | 43 二叉搜索树第 K 个值            | 中序访问顺序就是从小到大，访问到第 K 个节点后停止      |
| BFS + 每层取最右节点          | 44 二叉树的右视图                 | 每一层只记录最后访问的节点                             |
| 利用前序顺序原地展开          | 45 二叉树展开为链表               | 将左子树最右节点连接到原右子树，再将左子树移到右侧     |
| 前序确定根 + 中序划分左右子树 | 46 从前序与中序遍历序列构造二叉树 | 前序首元素确定根节点，中序中根的位置确定左右子树的范围 |

树形动态规划

| 具体方法                     | 对应题号与题目              | 关键思路                                                     |
| ---------------------------- | --------------------------- | ------------------------------------------------------------ |
| DFS + 前缀和 + 哈希表 + 回溯 | 47 路径总和 III             | 统计当前路径前缀和出现次数，查找 `cur-targetSum`，返回父节点前撤销当前路径的计数 |
| 后序递归 + 左右结果合并      | 48 二叉树的最近公共祖先节点 | 左右子树分别递归查找；若两边都找到目标节点，则当前节点是最近公共祖先 |
| 树形 DP + 后序遍历           | 49 二叉树的最大路径和       | 舍弃负贡献，向父节点返回单边最大收益，同时用左右两边更新全局最大路径和 |

### 35、中序遍历

```py
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode | None) -> list[int]:
        ans=[]
        def dfs(node):
            if node is None:
                return
            
            dfs(node.left)
            ans.append(node.val)
            dfs(node.right)
            
        dfs(root)
        return ans
```

### 36、二叉树最大深度

递归+取左右子树深度最大值+最后加上根节点的1

```py
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: TreeNode | None) -> int:
        if not root:
            return 0
            
        return max(self.maxDepth(root.left),self.maxDepth(root.right))+1
```



### 37、翻转二叉树

前序遍历+交换对侧节点

```py
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        #前序遍历+左右子树对侧交换
        def dfs(node):
            if not node:
                return
            node.left,node.right=node.right,node.left
            dfs(node.left)
            dfs(node.right)
        dfs(root)
        return root
```

### 38、对称二叉树

定义一个check函数交叉比较

```py
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: TreeNode | None) -> bool:
        #这个不是左右对称而是交叉比较
        def check(left,right):
            if not left and not right:
                return True
            if not left or not right:
                return False
                
            if left.val != right.val:
                return False
            
            #注意这里异侧比较
            return check(left.left,right.right) and check(left.right,right.left)
            
        if not root:
            return True
        return check(root.left,root.right)
```

### 39.二叉树的直径

遍历深度，结果就是直径，有点回溯的意思在。

这里还有个小坑就是self.ans，如果直接写ans的话，在depth函数作用域里会出现未定义ans的状况（`ans=max(ans,left+right)`,ans在外部函数被定义属于局部变量），需要写`nolocal`或者`global`

```cpp
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.ans=0
        def depth(node):
            if not node:
                return 0
            left=depth(node.left)
            right=depth(node.right)
            #更新一下答案
            self.ans=max(self.ans,left+right)
            return max(left,right)+1
        depth(root)
        return self.ans
```

### 40.二叉树的层序遍历

广度优先+用队列收集当前层的节点+列表存储每一层的值作答案

```py
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: TreeNode | None) -> list[list[int]]:
        #广度优先+队列存储当前层
        if not root:
            return []
        ans=[]
        queue=deque([root])

        while queue:
            cur_len = len(queue)
            cur_list_vals=[]
            for _ in range(cur_len):
                node=queue.popleft()
                cur_list_vals.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            #注意时机，遍历完当前层（也就是队列后再添加）
            ans.append(cur_list_vals)
        return ans
```

### 41.将有序数组转换成平衡二叉树

平衡二叉树：左右子树高度差不大于1

解法：分治+数组索引

```py
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: list[int]) -> TreeNode | None:
        #二叉树的中序遍历是升序的，所以数组就是中序遍历的结果
        #要构造平衡 BST，只需每次取数组中间元素作为根节点
        #解法：分治+利用好索引

        def build(left,right):
            if left>right:
                return None
            mid = (left+right)//2
            root=TreeNode(nums[mid])
            root.left=build(left,mid-1)
            root.right=build(mid+1,right)
            return root

        return build(0,len(nums)-1)
```

### 42.验证二叉搜搜书

二叉搜索树：左节点严格小于当前节点，右节点严格大于当前节点

中序遍历+一个递归函数+外设一个变量用于存储前一个值比较
原理：bst的中序即严格递增

```cpp
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode | None) -> bool:
        #中序遍历+递归判断
        self.prev=float('-inf')
        def inorder(node):#该函数作用是判断是否为二叉搜索树，用于递归
            if node is None:
                return True
            #前
            if not inorder(node.left):
                return False
            #中
            if node.val <= self.prev:
                return False
            self.prev=node.val
            return inorder(node.right)
        return inorder(root)

```

### 43.二叉搜索树第k个值

中序遍历+到k就停下+`定义一个返回值用于剪枝`否则只会在当前节点return result，其他节点依然在遍历

```cpp
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.count=0
        self.result=None
        def inorder(node):
            if not node or self.result is not None:
                return
            #左
            inorder(node.left)
            #根
            self.count+=1
            if self.count==k:
                self.result=node.val
                return
            #右
            inorder(node.right)
        inorder(root)
        return self.result
```

### 44.二叉树的右视图

层序遍历+循环到达每一层最右边节点+双端队列记录每层节点

```cpp
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        #层序遍历+双端队列
        if not root:
            return []
        ans=[]
        q=deque([root])
        
        while q:
            length=len(q)
            for i in range(length):
                node=q.popleft()
                if i==length-1:
                    ans.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
        return ans
```

### 45.二叉树展开为链表

利用前序特性

定义一个函数用于将每一个节点的右子树放到`左子树的最右节点`的右子树上，然后当前节点的右子树变成当前节点的左子树，当前节点的左子树滞空。

```cpp
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: TreeNode | None) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        #这题有点小难:原地操作，利用前序特性，构建一个函数，将每个节点的右子树挂到左子树最右节点，然后再把该节点左子树放到右边并滞空右子树
        cur=root
        while cur:
            if cur.left:
                pre=cur.left
                #找到左子树最右
                while pre.right:
                    pre=pre.right
                pre.right=cur.right
                cur.right=cur.left
                cur.left=None
            cur=cur.right#沿着新的right链移动
            
```

### 46.从前序与中序遍历序列构造二叉树

利用好递归+前序确定根节点，中序确定左右子树的长度+索引(根左右，左根右，长度就能确定子树范围。从而达到切分数组的效果。)

```py
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: list[int], inorder: list[int]) -> TreeNode | None:
        #递归+利用好前中序特性，拿到左右子树的索引
        if not preorder:
            return None
        
        root_val=preorder[0]
        root=TreeNode(root_val)
        idx=inorder.index(root_val)
                #这里利用好长度，然后将数组切分递归。
        root.left=self.buildTree(preorder[1:idx+1],inorder[:idx])
        root.right=self.buildTree(preorder[idx+1:],inorder[idx+1:])
        return root
        
```

### 47.路径总和lll

前缀和+哈希表统计次数+回溯

```cpp
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        #dfs+前缀和哈希表记录当前路径前缀和出现的次数
        self.count=0
        self.prefix={0:1}
        
        #cur表示当前的前缀和
        def dfs(node,cur):
            if not node:
                return 
            cur+=node.val
            self.count+=self.prefix.get(cur-targetSum,0)
            self.prefix[cur]=self.prefix.get(cur,0)+1
            dfs(node.left,cur)
            dfs(node.right,cur)
            #回溯
            self.prefix[cur]-=1
            if self.prefix[cur]==0:
                del self.prefix[cur]
                
        dfs(root,0)
        return self.count
```

### 48.二叉树的最近公共祖先节点

```py
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        #后序判断+递归
        if not root or root==p or root==q:
            return root
            
        left=self.lowestCommonAncestor(root.left,p,q)
        right=self.lowestCommonAncestor(root.right,p,q)
        
        if left and right:
            return root
        return left if left else right
```

### 49.二叉树的最大路径和

树形dp+后续+单边舍弃负值

dp是ans的值，会经历回溯。gain函数的返回值则是向上传递的状态。

```py
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: TreeNode | None) -> int:
        #后序树形dp+单边最大值舍弃负值
        self.ans=float("-inf")
        
        def gain(node):
            if not node:
                return 0
                
            left=max(0,gain(node.left))
            right=max(0,gain(node.right))
            self.ans=max(self.ans,node.val+left+right)
            #向上返回一条链
            return node.val+max(left,right)
        
        gain(root)
        return self.ans
```

## 图论

### 50.岛屿数量

利用沉岛法（由一处向四周扩散）+边界检查+dfs递归+一个变量用于统计

```cpp
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        #沉岛法(边界检查+四周扩散沉岛)+dfs递归
        if not grid:
            return 0
        count=0
        m=len(grid)
        n=len(grid[0])
        
        def dfs(i,j):
            if i<0 or i>=m or j<0 or j>=n or grid[i][j]!="1":
                return
            grid[i][j]='0'
            
            dfs(i+1,j)
            dfs(i-1,j)
            dfs(i,j+1)
            dfs(i,j-1)
            
        for i in range(m):
            for j in range(n):
                if grid[i][j]=="1":
                    count+=1
                    dfs(i,j)
        return count
                    
```

### 51.腐烂的橘子

多源bfs+层序遍历+双端队列存储与出队当前腐烂橘子的坐标与遍历时开始腐烂的橘子的新坐标+fresh统计新鲜数量

```py
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        #多源bfs层序遍历+队列存腐烂坐标+新鲜橘子标记
        m,n=len(grid),len(grid[0])
        q=deque()
        fresh=0
        
        for i in range(m):
            for j in range(n):
                if grid[i][j]==2:
                    q.append((i,j))
                elif grid[i][j]==1:
                    fresh+=1
                    
        if fresh==0:
            return 0
        mintues=0
        dirs=((1,0),(-1,0),(0,1),(0,-1))
        
        #多源bfs按层扩散
        
        while q and fresh>0:
            mintues+=1
            for _ in range(len(q)):
                x,y=q.popleft()
                for dx,dy in dirs:
                    nx,ny=dx+x,dy+y
                    if 0<=nx<m and 0<=ny<n and grid[nx][ny]==1:
                        grid[nx][ny]=2
                        fresh-=1
                        q.append((nx,ny))
                        
        return mintues if fresh==0 else -1
```

## 回溯

### 52.全排列

递归dfs+used标记+回溯（做选择->递归->回溯）+append拷贝值。

```py
class Solution:
    def permute(self, nums: list[int]) -> list[list[int]]:
        #回溯dfs(做选择+递归+撤销选择)+used标记+存拷贝
        n=len(nums)
        res=[]
        path=[]
        used=[False]*n
        
        def backtrace():
            if len(path)==n:
                #注意这里是拷贝
                res.append(path[:])
                return
                
            for i in range(n):
                if used[i]:
                    continue
                used[i]=True
                path.append(nums[i])
                backtrace()
                #回溯
                path.pop()
                used[i]=False
        backtrace()
        return res
```

### 53.子集

定义一个start状态+回溯+拷贝

```py
class Solution:
    def subsets(self, nums: list[int]) -> list[list[int]]:
        n=len(nums)
        path=[]
        res=[]
        
        def backtrace(start):
            res.append(path[:])
            for i in range(start,n):
                path.append(nums[i])
                backtrace(i+1)
                path.pop()
        backtrace(0)
        return res
                
```

### 54.电话号码的数字组合

字典存储映射+index索引用于标记目前在处理哪个数字+递归+回溯+子树收集（也就是满足索引等于digits的长度）

```py
class Solution:
    def letterCombinations(self, digits: str) -> list[str]:
        if not digits:
            return []
        mapping = {
            '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl',
            '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'
        }
        res = []
        path = []

        def backtrace(index):
            if index==len(digits):
                res.append(''.join(path))
                return 
            
            words=mapping[digits[index]]
            for ch in words:
                path.append(ch)
                backtrace(index+1)
                path.pop()
        backtrace(0)
        return res
```

### 55.组合总和

和子集、组合同类型+start和remain用来递归+无重复则可以不+1 +回溯+剪纸

```py
class Solution:
    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        #和子集、组合相同类型，需要一个start来跳过自身+回溯+可重复就不需要+1 +剪纸
        n=len(candidates)
        path=[]
        res=[]

        def backtrace(start,remain):
            if remain==0:
                res.append(path[:])
                return

            #剪纸
            if remain<0:
                return

            for i in range(start,n):
                path.append(candidates[i])
                backtrace(i,remain-candidates[i])
                path.pop()

        backtrace(0,target)
        return res
```

### 56.括号生成

这一题不需要用到栈，原因是他给了个n，所以按照如下两个约束即可：左括号<n，右括号<左括号。path里的括号数达到2n时收集。

```cpp
class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        '''
        这题不需要栈，因为它给了n，所以只需要以下两个就能判断是否合规
        左括号数 < n 时，可以放 (；
        右括号数 < 左括号数 时，可以放 )。
        '''
        path=[]
        res=[]

        def backtrace(left,right):
            if len(path)==n*2:
                res.append(''.join(path))
                return
            
            if left<n:
                path.append('(')
                backtrace(left+1,right)
                path.pop()

            if right<left:
                path.append(')')
                backtrace(left,right+1)
                path.pop()

        backtrace(0,0)
        return res
```

### 57.单词搜索

这题很像岛屿数量，不过需要标记并回溯修复，并且返回bool+用k来当索引。

```py
class Solution:
    def exist(self, board: list[list[str]], word: str) -> bool:
        #这道题类似于沉岛法，不过要回溯修复+三个参数，两方向一统计数量+剪纸
        m=len(board)
        n=len(board[0])
        dirs = ((-1,0),(1,0),(0,-1),(0,1))
        def dfs(i,j,k):
            if k==len(word):
                return True
            
            if i<0 or i>=m or j<0 or j>=n or board[i][j]!=word[k]:
                return False

            #标记为已经访问
            board[i][j]='#'
            for nx,ny in dirs:
                if(dfs(i+nx,j+ny,k+1)):
                    return True
            board[i][j]=word[k]#回溯
            return False

        for i in range(m):
            for j in range(n):
                if dfs(i, j, 0):
                    return True
        return False

```

### 58.分割字符串

定义一个用于判断回文的函数+回溯+用start标志每次切开的位置+添加时注意索引

```py
class Solution:
    def partition(self, s: str) -> list[list[str]]:
        n=len(s)
        path=[]
        res=[]
        
        
        def is_re(l,r):
            while l<r:
                if s[l]!=s[r]:
                    return False
                l+=1
                r-=1
            return True
                
        def back(start):
            if start==n:
                res.append(path[:])
                return
                
            for i in range(start,n):
                if is_re(start,i):
                    path.append(s[start:i+1])
                    back(i+1)
                    path.pop()
                    
        back(0)
        return res
            
```

## 二分查找

### 59.搜索插入位置

二分法+注意循环条件不要漏掉left=right的情况+最后返回left也就是最左边的插入位置点。

```py
class Solution:
    def searchInsert(self, nums: list[int], target: int) -> int:
        n=len(nums)
        left=0
        right=n-1
        while left<=right:
            mid=(left+right)//2
            if nums[mid]<target:
                left=mid+1
            elif nums[mid]>target:
                right=mid-1
            else:
                return mid
        return left
       
```

### 60.搜索二维矩阵

将二维转成一维+行用`//n表示`，列用`%n`表示

```py
class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        m=len(matrix)
        n=len(matrix[0])
        left=0
        right=m*n-1
        
        while left<=right:
            mid=(left+right)//2
            val=matrix[mid//n][mid%n]
            if val>target:
                right=mid-1
            elif val<target:
                left=mid+1
            else:
                return True
                
        return False
```

### 61.在排序数组中查找元素的第一个和最后一个位置

两次二分+两个候选值（注意if分支只有两端了，因为候选值要不断更新，逼近左右边界）

```py
class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        #两次二分查找，分别找出左右边界+利用好两个候选值
      n=len(nums)  
      if n==0:
          return [-1,-1]
          
      left=0
      right=n-1
      first=-1#候选者
      while left<=right:
          mid=(left+right)//2
          if nums[mid]>=target:
              if nums[mid]==target:
                   first=mid
              right=mid-1
          else:
              left=mid+1
      if first==-1:
          return[-1,-1]
      
      left=0
      right=n-1
      last=-1#候选者
      while left<=right:
          mid=(left+right)//2
          if nums[mid]<=target:
              if nums[mid]==target:
                   last=mid
              left=mid+1
          else:
              right=mid-1
      if last==-1:
          return [-1,-1]
          
      return [first,last]
```

### 62.搜索旋转数组

二分法+判断mid劈开后左右那一段是有序的

```py
class Solution:
    def search(self, nums: list[int], target: int) -> int:
        #带条件的二分法+判断两边哪一边有序+每次二分暴力劈两端后，必定有一段是有序的。
        left=0
        right=len(nums)-1

        while left<=right:
            mid=(right+left)//2
            if nums[mid] == target:
                return mid
            
            if nums[left]<=nums[mid]:#左边有序
                if nums[left]<=target<=nums[mid]:
                    right=mid-1
                else:
                    left=mid+1

            else:                                 # 右半有序
                if nums[mid] < target <= nums[right]:
                    left = mid + 1               # target 在右半
                else:
                    right = mid - 1              # 去左半
        return -1
```

### 63.寻找旋转排序数组中的最小值

还是利用好上一题的性质即劈开后必定有段连续+只需要对比mid和right的值即可，因为找最小值不需要像上一条要找**任意 target**那样面面俱到。这题**只找最小值**，而最小值就是**旋转点（断崖的右端）**。

注意死循环：`while left < right` 不能写 `<=`

写 `<=` 且 `right = mid` 会**死循环**（`left == right` 时 `mid == left`，`right = mid` 不变）。这是本题头号坑。

```py
class Solution:
    def findMin(self, nums: list[int]) -> int:
        left=0
        right=len(nums)-1

        while left<right:
            mid=(left+right)//2
            if nums[mid]>nums[right]:
                left=mid+1
            else:
                right=mid #注意这里，最小值在左半部分可能包含。
        return nums[left] #最后返回left对应的值即可。
```

## 栈

### 64.有效的括号

栈得一直处于空空的状态+哈希表存对应关系+最后返回值是判断栈是否空

```py
class Solution:
    def isValid(self, s: str) -> bool:
        stack=[]
        pair = {')': '(', '}': '{', ']': '['}
        
        for ch in s:
            if ch in "{[(":
                stack.append(ch)
            else:
                if not stack or stack[-1]!=pair[ch]:
                    return False
                stack.pop()
                    
        return not stack
```

### 65.最小栈

初始化两个栈+一个栈存数据，另一个存到i+1时的最小值（类似于前缀和）

```py
class MinStack:

    def __init__(self):
        self.stack=[]
        self.min_stack=[]

    def push(self, value: int) -> None:
        self.stack.append(value)
        if self.min_stack:
            self.min_stack.append(min(self.min_stack[-1],value))
        else:
            self.min_stack.append(value)

    def pop(self) -> None:
        self.stack.pop()
        self.min_stack.pop()

    def top(self) -> int:
        return self.stack[-1]
        

    def getMin(self) -> int:
        return self.min_stack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(value)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
```

### 66.字符串解码

定义三个变量：栈用于记录之前的结果+num统计数字+isdigit判断整数+cur用于存储目前的字符串+分情况处理左右括号

```py
class Solution:
    def decodeString(self, s: str) -> str:
        stack=[]
        cur=""
        num=0

        for ch in s:
            if ch.isdigit():
                num=num*10+int(ch)
            else:
                if ch=='[':
                    stack.append((cur,num))
                    num=0
                    cur=""
                elif ch==']':
                    prev,repeat=stack.pop()
                    cur=prev+cur*repeat
                else:
                    cur+=ch
        return cur
```

### 67.每日温度

单调递减栈+**栈里面保存的是还没有找到目标温度的下标**+answer记录答案+利用好下标即下标作索引对应answer的天数差差

```py
class Solution:
    def dailyTemperatures(self, temperatures: list[int]) -> list[int]:
        n=len(temperatures)
        stack=[]
        answer=[0]*n

        for i in range(n):
            while stack and temperatures[stack[-1]]<temperatures[i]:
                prev=stack.pop()
                answer[prev] = i-prev
            stack.append(i)
        return answer

```

### 68.柱状图中的最大矩形

单调递增栈+首尾哨兵+先弹出后拿左边界+计算宽度时-1.

```py
class Solution:
    def largestRectangleArea(self, heights: list[int]) -> int:
        #单调递增栈+首尾哨兵0
        stack=[]
        heights=[0]+heights+[0]
        max_area=0

        for i in range(len(heights)):
            while stack and heights[stack[-1]]>heights[i]:
                h=heights[stack.pop()]
                left=stack[-1]
                right=i
                width=right-left-1
                max_area = max(max_area, h * width)
            stack.append(i)

        return max_area

```

## 堆

### 69.数组中的第K个最大元素

这题可以用块排，也可以用小丁堆。

小顶堆写法如下：

```py
import heapq

class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        heap = []
        for x in nums:
            heapq.heappush(heap, x)
            if len(heap) > k:
                heapq.heappop(heap)     # 弹掉最小的，保留最大的 k 个
        return heap[0]                  # 小顶堆堆顶 = 第 k 大
```

快排：找一个随机数索引和最右边的交换位置+partition：把 `≤ pivot` 的放左边这样>pivot的就会跑到右边+归为p+P存的是索引！

这里还得三路快排，不然会超时

```py
import random
from typing import List
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        target = len(nums)-k
        def quick_select(left, right):
            pivot = nums[random.randint(left, right)]
            lt, i, gt = left, left, right
            while i <= gt:
                if nums[i] < pivot:
                    nums[lt], nums[i] = nums[i], nums[lt]
                    lt += 1; i += 1
                elif nums[i] > pivot:
                    nums[i], nums[gt] = nums[gt], nums[i]
                    gt -= 1
                else:
                    i += 1
            # 现在 [left, lt-1] < pivot, [lt, gt] == pivot, [gt+1, right] > pivot
            if target < lt:
                return quick_select(left, lt - 1)
            elif target > gt:
                return quick_select(gt + 1, right)
            else:
                return nums[target]   # target 落在 == pivot 区间

        return quick_select(0, len(nums) - 1)
```

两路快排：

```py
import random
from typing import List
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        target = len(nums)-k
        def quick_select(left,right):
            pivot_id = random.randint(left,right)
            nums[pivot_id],nums[right]=nums[right],nums[pivot_id]
            pivot = nums[right]

            p=left
            for i in range(left,right):
                if nums[i]<=pivot:
                    nums[p],nums[i]=nums[i],nums[p]
                    p += 1
            nums[p], nums[right] = nums[right], nums[p]   # pivot 归位

            if p == target:
                return nums[p]
            elif p < target:
                return quick_select(p + 1, right)
            else:
                return quick_select(left, p - 1)

        return quick_select(0, len(nums) - 1)
```

### 70.前k个高频元素

1. 用 `Counter` 统计每个元素的频率；
2. 维护一个**大小为 k 的小顶堆**，堆里存 `(频率, 元素)`，按频率比较；
3. 遍历频率表，堆满 k 个后，若当前频率 > 堆顶频率，弹出堆顶、压入当前；
4. 最后堆里就是频率前 k 高的元素。

```py
class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        #哈希表+小顶堆
        count = Counter(nums)#统计频率
        heap=[]
        for num,freq in count.items():
            heapq.heappush(heap,(freq,num))
            if len(heap) > k:
                heapq.heappop(heap)            # 弹掉频率最小的
        return [num for freq, num in heap]
```

## 贪心算法

### 71.股票买卖最佳时机

定义利润和花费（花费就是某一天的股价）+计算最小的花费+计算最大的利润+遍历价格。

```py
class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        cost,profit=float('inf'),0
        for price in prices:
            cost=min(price,cost)
            profit=max(profit,price-cost)
        return profit


```

### 72.跳跃游戏

这个是看能不能跳到最后

定义一个贪心跨步变量maxreach+如果`当前索引i>maxreach`那么说明永远都不可能到达最终点。

如果maxreach能够到n-1的位置说明正确。

```py
class Solution:
    def canJump(self, nums: list[int]) -> bool:
        mxreach=0
        n=len(nums)
        for i in range(n):
            if i>mxreach:
                return False
            mxreach=max(mxreach,i+nums[i])
            if mxreach>=n-1:
                return True
        return True
```

### 73.跳跃游戏ll

这关是保证能够跳到最后的+要的答案是最少的次数

我们利用层序遍历+定义一个end变量用于记录每一层超过就赋值为maxpos+循环到n-2避免多跳。

```py
class Solution:
    def jump(self, nums: list[int]) -> int:
        #和层序遍历差不多+遍历完每一层+它保证了能够跳到n-1所以循环结束就是跳跃次数+n-1的位置不跳。
        n=len(nums)
        ans=0
        maxpos=0
        end=0

        for i in range(n-1):
            maxpos=max(maxpos,i+nums[i])
            if i==end:
                ans+=1
                end=maxpos #进入下一层
        return ans
```

### 74.划分字母区间

统计每个字母出现的最后的位置

维护start和end。end是共享的，start是每次下标遍历到end时作更新。

```py
class Solution:
    def partitionLabels(self, s: str) -> list[int]:
        #先遍历一遍统计每个字母最远出现的位置+维护start和end。
        last={}
        for i,ch in enumerate(s):
            last[ch]=i#记录每个字母最后出现的位置
        
        res=[]
        start=0
        end=0
        for i,ch in enumerate(s):
            end=max(end,last[ch])
            if i==end:
                res.append(end-start+1)
                start=i+1
        return res

```

## 动态规划

### 75.爬楼梯

动态规划：这题本质斐波那契。

将爬楼这个状态简化成到最后选爬一下还是两下的函数递归抽象问题。

```py
class Solution:
    def climbStairs(self, n: int) -> int:
        @cache
        def dfs(n):
            if n<=1:
                return 1
            return dfs(n-1)+dfs(n-2)
        return dfs(n)
```

### 76.杨辉三角

找规律：这一层的`[i][j]=[i-1][j-1]+[i-1][j]`

另外单独用一个变量记录`row`

```py
class Solution:
    def generate(self, numRows: int) -> list[list[int]]:
        res=[]
        for i in range(numRows):
            row=[1]*(i+1)
            for j in range(1,i):
                row[j] = res[i-1][j-1]+res[i-1][j]
            res.append(row)
        return res
```

### 77.打家劫舍

利用dp数组

先判断1条件然后初始化dp数组的前两个

然后再从1开始遍历到n，要求满足`dp[i]=max(dp[i-1],dp[i-2]+nums[i])`，要么不偷取前一家，要么偷这家+前前一家的钱。

```py
class Solution:
    def rob(self, nums: List[int]) -> int:
        #动态规划对一间房要么偷要么不偷：dp[i] = max(dp[i-1], dp[i-2] + nums[i])
        #优先判断1条件+单独初始化dp前两个
        n=len(nums)
        if n==1:
            return nums[0]
        dp=[0]*n
        dp[0]=nums[0]
        dp[1]=max(nums[0],nums[1])

        for i in range(2,n):
            dp[i]=max(dp[i-1],dp[i-2]+nums[i])
        return dp[-1]
```

### 78.完全平方数

完全背包（里面的物品能够无限取）+dp[i]表示和为i时最少的完全平方数个数

转换问题变成：`遍历比i小的完全平方数+比较当前的dp[i]和j*j看用不用上这个完全平方数，如果用，就找到之前已经有的dp[i-j*j]+1即可，这个代表选上当前的完全平方数。`

```py
class Solution:
    def numSquares(self, n: int) -> int:
        #dp[i] = 和为 i 的最少完全平方数个数。+完全背包
        dp=[float('inf')]*(n+1)
        dp[0]=0
        for i in range(1,n+1):
            j=1
            while j**2<=i:
                dp[i]=min(dp[i],dp[i-j**2]+1)
                j+=1
        return dp[-1]
```

错误写法：时间爆炸

```py
class Solution:
    def numSquares(self, n: int) -> int:
        dp=[float('inf')]*(n+1)
        dp[0]=0
        for i in range(1,n+1):
            for j in range(i):
                if i>=j*j:
                    dp[i]=min(dp[i],dp[i-j*j]+1)
        return dp[n]
    
需要优化成for j in range(1, int(i**0.5) + 1):
    dp[i] = min(dp[i], dp[i - j*j] + 1)
```



### 79.零钱兑换

和上一题大差不差

多了个条件判断。

```py
class Solution:
    def coinChange(self, coins: list[int], amount: int) -> int:
        if amount==0:
            return 0
        dp=[float('inf')]*(amount+1)
        dp[0]=0
        for i in range(1,amount+1):
            for coin in coins:
                if i>=coin:
                    dp[i]=min(dp[i],dp[i-coin]+1)
        return dp[amount] if dp[amount]!=float('inf') else -1
```

### 80.单词拆分

`dp[i]表示i之前可以用那个数组拼出来`

用两层循环将到目前为止的字符串拆成两半，dp[j]和dp[j:i]

```py
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        #dp[i]表示前i个是否能被拼出，存bool.也就是将一个字母拆成前后两半
        n=len(s)
        word_set=set(wordDict)
        dp=[False]*(n+1)
        dp[0]=True

        for i in range(1,n+1):
            for j in range(i):
                if dp[j] and s[j:i] in word_set:
                    dp[i]=True
                    break
        return dp[n]

```

### 81.最长递增子序列

设定dp[i]为以nums[i]结尾的最长长度。

这一题dp[i]就是对应每个的下标，而不是前i个，所以不需要额外多一个0

最后返回值也因此得额外加一个返回`max(dp)`

```py
class Solution:
    def lengthOfLIS(self, nums: list[int]) -> int:
        #设 dp[i] = 以 nums[i] 结尾的最长严格递增子序列长度。对每个 i，枚举 j < i，若 nums[j] < nums[i]，则可以把 i 接在 j 后面：
        n=len(nums)
        dp=[1]*n
        for i in range(n):
            for j in range(i):
                if nums[j]<nums[i]:
                    dp[i] = max(dp[i],dp[j]+1)
        return max(dp)
```

### 82.乘积最大子数组

同时维护max和min以及比较时是比较三个变量。

```py
class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        #由于存在负数，所以这里要同时维护max和min
        maxp=minp=nums[0]
        ans=nums[0]
        for x in nums[1:]:
            candidates=(x,maxp*x,minp*x)
            maxp = max(candidates)
            minp = min(candidates)
            ans = max(ans, maxp)
        return ans
```

### 83.分割等和子集

不完全背包+先判断是否和为偶数+倒序遍历

`dp[j] = 能不能从"已经考虑过的数"里，挑出一些，使它们的和恰好为 j`

**最终答案**：`dp[target]`，即"能不能凑出 target"。

关键动作：**考虑一个新数 `x` 时，`dp` 怎么变？**

对每个和 `j`，有两种可能：

- **不选 `x`**：那 `dp[j]` 保持原样（之前能凑出就还能，凑不出就还凑不出）；
- **选 `x`**：那需要"**之前能凑出 `j - x`**"，加上 `x` 就凑出 `j`。即看 `dp[j - x]` 是否为 True。

```py
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        #不完全背包，从包里选元素看是否等和。
        total=sum(nums)
        if total%2==1:
            return False
        target=total//2
        dp=[False]*(target+1)
        dp[0]=True
        for x in nums:
            for j in range(target,x-1,-1):
                dp[j]=dp[j] or dp[j-x]
        return dp[target]
```

### 84.最长有效括号

单纯的栈存下标即可解决，另外还要添置一个哨兵-1，遇到右括号就弹，弹空了就把当前下标存进去当哨兵。

```py
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        #栈栈存下标，并且用哨兵标记，遇到）就弹出
        stack=[-1]
        ans=0
        for i,ch in enumerate(s):
            if ch =='(':
                stack.append(i)
            else:
                stack.pop()
                if not stack:#说明把哨兵弹出去了，栈里本来也没有能用来匹配的左括号
                    stack.append(i)#把新的右括号加进去当哨兵
                else:
                    ans=max(ans,i-stack[-1])

        return ans

```

## 多维动态规划

### 85.不同路径

设 dp[i][j] = 从左上角 (0,0) 走到 (i,j) 的路径数。

那么最后一步走到`[i][j]`就可以有两种表示：从目标的上方或者从目标的左方。

另外返回值别忘了-1，行列号是从零开始。

```py
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        #设 dp[i][j] = 从左上角 (0,0) 走到 (i,j) 的路径数。
        dp=[[1]*n for _ in range(m)]#第一行和第一列都只有一条路径
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j]=dp[i-1][j]+dp[i][j-1]
        return dp[m-1][n-1]
```

### 86.最小路径和

定义dp状态为`dp[i][j]=从（0，0）到（i,j)的最小路径和`

额外处理第一行和第一列，他们只有一种走法。

初始化二维数组全为0，第一个直接赋值。

```py
class Solution:
    def minPathSum(self, grid: list[list[int]]) -> int:
        #设 dp[i][j] = 从 (0,0) 走到 (i,j) 的最小路径和。
        m=len(grid)
        n=len(grid[0])
        dp=[[0]*n for _ in range(m)]
        dp[0][0]=grid[0][0]

        #第一行和第一列是特殊情况
        for j in range(1,n):
            dp[0][j]=dp[0][j-1]+grid[0][j]
        for i in range(1,m):
            dp[i][0]=dp[i-1][0]+grid[i][0]
        
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1])
        return dp[m-1][n-1]
```

## 技巧

### 87.只出现一次的数

初始值为0然后异或

```py
class Solution:
    def singleNumber(self, nums: list[int]) -> int:
        ans=0
        for num in nums:
            ans=ans^num
        return ans
```

### 88.多数元素

投票，预设两个变量candidate和count。

遇到相同元素count+1，当count=0时，更新candidate

```py
class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        #投票抵消，把多数元素和其他的互相抵消。
        candidate=0
        count=0
        for x in nums:
            if count==0:
                candidate=x
            if candidate==x:
                count+=1
            else:
                count-=1
        return candidate
```

