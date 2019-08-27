import collections
import bisect


class TimeMap:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._internal = collections.defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self._internal[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        a = self._internal[key]
        i = bisect.bisect(a, (timestamp, chr(127)))
        return a[i - 1][1] if i != 0 else ""


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
