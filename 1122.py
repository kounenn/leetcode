class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        res = []
        bucket = [0 for _ in range(1001)]
        for n in arr1:
            bucket[n] +=1
        for n in arr2:
            for _ in range(bucket[n]):
                res.append(n)
            bucket[n] = 0
        s = []
        for n in arr1:
            if bucket[n]>0:
                s.append(n)
        s.sort()
        res.extend(s)
        return res
