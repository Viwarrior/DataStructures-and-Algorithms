class TreeNode:
    def __init__(self,value):
        self.left = None
        self.right = None
        self.val = value

class AVL:
    def __init__(self):
        self.root = None
    def insert(self,value):
        t = TreeNode(value)
        if self.root == None:
            self.root = t
        else:
            current = self.root
            while(current != None):
                parent = current
                if current.val< value:
                    current = current.right
                    if current == None:
                        parent.right = t
                        
                else:
                    current = current.left
                    if current == None:
                        parent.left = t

    def binarysearch(self,value,node):
        if node.val == value:
            return(True,node)
        elif node.val< value:
            return(self.binarysearch(value, node.right))
        else:
            return(self.binarysearch(value, node.left))
        


    
    def preorder(self,node):
        if node == None:
            return
        print(node.val, end=" ")
        self.preorder(node.left)
        self.preorder(node.right)
    def inorder(self,node):
        if node == None:
            return
        self.inorder(node.left)
        print(node.val, end=" ")
        self.inorder(node.right)
    def postorder(self,node):
        if node == None:
            return
        self.postorder(node.left)
        self.postorder(node.right)
        print(node.val, end=" ")

    def returnroot(self):
        return(self.root)

    def delete_element(self,value,node):
        if value<node.val:
            node.left = self.delete_element(value,node.left)
        elif value>node.val:
            node.right = self.delete_element(value,node.right)
        else:
            #found element
            if node.left == None and node.right ==None:
                node = None
            elif node.left !=None and node.right !=None:
                small= node.right
                while(small.left!=None):
                    small = small.left
                if small.right == None:
                    node.val = small.val
                    node.right = self.delete_element(small.val,node.right)  # and not  just delete_element
                else:
                    node = node.right
            else:
                if node.left!=None:
                    node = node.left
                else:
                    node = node.right
        return(node) #outside all condition statements

        #following will not work because if you have to make changes to a node then changes should reflect all the way to self.root (keep a parent node to track)
        # _ , node = self.binarysearch(value,self.root)
        # if node.left == None and node.right ==None:
        #     node = None
        # elif node.left !=None and node.right !=None:
        #     small= node
        #     while(small.left!=None):
        #         small = small.left
        #     if small.right == None:
        #         node.val = small.val
        #         small = None
        #     else:
        #         node = node.right
        # else:
        #     if node.left!=None:
        #         node = node.left
        #     else:
        #         node = node.right


        

    def delete_tree(self):
        self.root = None
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
    
if __name__ == "__main__":
    b = AVL()
    b.insert(9)
    b.insert(3)
    b.insert(1)
    b.insert(18)
    b.insert(5)
    b.insert(2)
    # b.insert(12)
    # b.insert(23)
    # b.insert(45)
    # b.insert(22)
    # b.insert(63)
    print(b.binarysearch(5,b.returnroot()))
    b.levelOrderTraversal()
    b.postorder(b.returnroot())
    b.delete_element(9,b.returnroot())
    print("\n")
    b.postorder(b.returnroot())

                
