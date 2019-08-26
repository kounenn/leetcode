# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """

        data_list = []

        def traversal(root):
            if not root:
                data_list.append('')
                return
            data_list.append(str(root.val))
            traversal(root.left)
            traversal(root.right)
        traversal(root)
        return ' '.join(data_list)

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """

        data_list = data.split(' ')

        def traversal(index):
            val = data_list[index]
            if not val:
                return None, index
            root = TreeNode(int(val))
            root.left, index = traversal(index + 1)
            root.right, index = traversal(index + 1)
            return root, index
        return traversal(0)[0]


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
