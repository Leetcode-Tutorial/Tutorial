class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sz = len(nums)
        last, step = 0, [0]*sz
        for i in xrange(sz):
            for j in xrange(last+1, min(i+nums[i]+1, sz)):
                step[j] = step[i]+1
            last = max(last, i+nums[i])
        return step[sz-1]
