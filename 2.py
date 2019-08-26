#  Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        r = l = ListNode(0)
        temp = 0
        while True:
            s = temp
            if l1:
                s += l1.val
                l1=l1.next
            if l2:
                s += l2.val
                l2=l2.next
            temp,l.val = divmod(s,10)
            if l1 or l2 or temp:
                l.next = ListNode(0)
                l = l.next
            else:
                break      
        
        return r