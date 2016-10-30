import sys

class Node:
    def __init__(self,data):
        self.right=self.left=None
        self.data = data
class Solution:
    def insert(self,root,data):
        if root==None:
            return Node(data)
        else:
            if data<=root.data:
                cur=self.insert(root.left,data)
                root.left=cur
            else:
                cur=self.insert(root.right,data)
                root.right=cur
        return root
    def levelOrder(self,root):
        if root == None:
            return
        else:
            x = list()
            x.append(root)
            while x.__len__() > 0:
                current = x[0]
                del(x[0])
                print(current.data,end=' ')
                if current.left:
                    x.append(current.left)
                if current.right:
                    x.append(current.right)

T=int(input())
myTree=Solution()
root=None
for i in range(T):
    data=int(input())
    root=myTree.insert(root,data)
myTree.levelOrder(root)
