
class TreeNode:
    def __init__(self,value):
        self.left = None
        self.right = None
        self.val = value

class Tree:
    def __init__(self):
        self.root = None
    def insert(self,value):
        t = TreeNode(value)
        if self.root == None:
            self.root = t
        else:
            q = []
            q.append(self.root)
            while(len(q)!=0):
                if q[0].left!=None:
                    q.append(q[0].left)
                else:
                    q[0].left = t
                    return
                if q[0].right!=None:
                    q.append(q[0].right)
                else:
                    q[0].right = t
                    return
                q.pop(0)
    def levelOrderTraversal(self):
        if self.root == None:
            return
        q = []
        q.append(self.root)
        while(len(q)!=0):
            if q[0].left!=None:
                q.append(q[0].left)
            if q[0].right!=None:
                q.append(q[0].right)
            v = q.pop(0)
            print(v.val,end=" ")
        print(end="\n")
    def parent_with_lchild(self,value):
        if self.root == None:
            return(None)
        q = []
        q.append(self.root)
        while(len(q)!=0):
            if q[0].left!=None:
                if q[0].left.val == value:
                    return(q[0].val)
                q.append(q[0].left)
            if q[0].right!=None:
                q.append(q[0].right)
            q.pop(0)
        return(None)
    def parent_with_rchild(self,value):
        if self.root == None:
            return(None)
        q = []
        q.append(self.root)
        while(len(q)!=0):
            if q[0].left!=None:
                q.append(q[0].left)
            if q[0].right!=None:
                if q[0].right.val == value:
                    return(q[0].val)
                q.append(q[0].right)
            q.pop(0)
        return(None)
    def lchild(self,value):
        if self.root == None:
            return(None)
        q = []
        q.append(self.root)
        while(len(q)!=0):
            if q[0].left!=None:
                if q[0].val == value:
                    return(q[0].left.val)
                q.append(q[0].left)
            if q[0].right!=None:
                q.append(q[0].right)
            
            q.pop(0)
        return(None)
    def rchild(self,value):
        if self.root == None:
            return(None)
        q = []
        q.append(self.root)
        while(len(q)!=0):
            if q[0].left!=None:
                q.append(q[0].left)
            if q[0].right!=None:
                if q[0].val == value:
                    return(q[0].right.val)
                q.append(q[0].right)
            q.pop(0)
        return(None)
    def node_exists(self,value):
        if self.root == None:
            return("Tree empty")
        q = []
        q.append(self.root)
        while(len(q)!=0):
            if q[0].left!=None:
                q.append(q[0].left)
            if q[0].right!=None:
                q.append(q[0].right)
            if q[0].val == value:
                    return(True,q[0])
            q.pop(0)
        return(False,None)
    def _preorder(self,node):
        if node == None:
            return
        print(node.val, end=" ")
        self._preorder(node.left)
        self._preorder(node.right)

    def preorder_traverse(self,value):
        yorn ,t = self.node_exists(value)
        if yorn:
            self._preorder(t)
            print(end="\n")
        else:
            print("Empty tree!")
    
    def _inorder(self,node):
        if node == None:
            return
        self._inorder(node.left)
        print(node.val, end=" ")
        self._inorder(node.right)

    def inorder_traverse(self,value):
        yorn ,t = self.node_exists(value)
        if yorn:
            self._inorder(t)
            print(end="\n")
        else:
            print("Empty tree!")
    
    def _postorder(self,node):
        if node == None:
            return
        self._postorder(node.left)
        self._postorder(node.right)
        print(node.val, end=" ")

    def postorder_traverse(self,value):
        yorn ,t = self.node_exists(value)
        if yorn:
            self._postorder(t)
            print(end="\n")
        else:
            print("Node not found!")
    
    def _extract_value(self,node):
        return(node.val)
    
    def find_parent(self,value):
        if self.root == None:
            return(None)
        q = []
        q.append(self.root)
        while(len(q)!=0):
            if q[0].left!=None:
                if q[0].left.val == value:
                    return(q[0],"l")
                q.append(q[0].left)
            if q[0].right!=None:
                if q[0].right.val == value:
                    return(q[0],"r")
                q.append(q[0].right)
            q.pop(0)
        return(None)

    def delete_node(self,value):
        yorn ,t = self.node_exists(value)
        if yorn:
            q = []
            q.append(self.root)
            while(len(q)!=0):
                if q[0].left!=None:
                    q.append(q[0].left)
                if q[0].right!=None:
                    q.append(q[0].right)
                q.pop(0)
                if len(q)==1:
                    p, child = self.find_parent(q[0].val)
                    t.val = q[0].val
                    if child == "l":
                        p.left = None
                    elif child == "r":
                        p.right= None
        else:
            print("Node not found!")

    def delete_tree(self):
        self.root = None
if __name__ == "__main__":
    tree =  Tree()
    tree.insert(3)
    tree.insert(4)
    tree.insert(5)
    tree.insert(7)
    tree.insert(23)
    tree.insert(22)
    tree.insert(1)
    tree.delete_node(5)
    tree.postorder_traverse(3)
    print(tree.parent_with_rchild(5))
    print(tree.parent_with_rchild(3))
    print(tree.rchild(3))
    print(tree.rchild(4))
    print(tree.node_exists(9))
    print(tree.node_exists(5))
    tree.delete_node(3)
    tree.levelOrderTraversal()
        

