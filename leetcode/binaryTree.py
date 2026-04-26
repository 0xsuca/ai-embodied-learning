class binaryTree:
    def __init__(self, left = None, right = None, value = None):
        self.left = left
        self.right = right
        self.value = value

    def revert(self, node):

        if node == None:
            return
        if node.left == None and node.right == None:
            return

        tmp = node.left
        node.left = node.right
        node.right = tmp

        self.revert(node.left)
        self.revert(node.right)

    def DFS_preorder(self):

    def preorder_print(self, root):
        if root is None:
            return
        print(root.value, end=' ')      # 访问根
        self.preorder_print(root.left)     # 递归左子树
        self.preorder_print(root.right)




if __name__ == '__main__':
    s1 = binaryTree(value=1)
    s3 = binaryTree(value=3)
    s6 = binaryTree(value=6)
    s9 = binaryTree(value=9)
    s2 = binaryTree(s1,s3,2)
    s7 = binaryTree(s6,s9,7)
    s4 = binaryTree(s2,s7,4)

    s4.revert(s4)

    s4.preorder_print(s4)
