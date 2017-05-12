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
        s = []
        def dfs(rt):
            if rt is None:
                s.append(str(rt))
                return
            s.append(str(rt.val))
            dfs(rt.left)
            dfs(rt.right)
        dfs(root)
        return " ".join(s)

        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        self.pos = -1
        s = data.split()
        def dfs():
            self.pos += 1
            if s[self.pos] == str(None): return None
            node = TreeNode(int(s[self.pos]));
            node.left = dfs()
            node.right = dfs()
            return node
        root = dfs()
        return root
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
