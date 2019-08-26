# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummy = cur = ListNode(0)
        cur.next = l1
        while l1 and l2:
            if l1.val < l2.val:
                l1 = l1.next
            else:
                # 1次只取1个结点
                n = cur.next
                t = l2.next
                cur.next = l2
                l2.next = n
                l2 = t
            cur = cur.next
        cur.next = l1 or l2
        return dummy.next
