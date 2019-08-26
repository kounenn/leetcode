# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """

        h = head
        size = 0
        while h:
            h=h.next
            size+=1
        h = head
        p = None
        n_ = h.next
        i = 0
        while h:
            if i == size-n:
                if p:
                    p.next = n_
                else: # 第一个结点
                    head = head.next
                break
            p = h
            h = n_
            n_ = h.next if h else None
            i+=1

        return head