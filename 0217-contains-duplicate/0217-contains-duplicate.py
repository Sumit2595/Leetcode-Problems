class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        positive = 0
        negative = 0
        for num in nums:
            if(num >=0):
                if((positive & (1<<num)) > 0):
                    return True
                positive|=(1<<num)
            else:
                num=abs(num)
                if((negative & (1<<num)) > 0):
                    return True
                negative|=(1<<num)
        return False
        