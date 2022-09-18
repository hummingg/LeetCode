class Solution:
    def numColor(self, root: TreeNode) -> int:
        st = set()

        def preorder(root: TreeNode):
            if not root:
                return
            nonlocal st
            st.add(root.val)
            preorder(root.left)
            preorder(root.right)
            
        preorder(root)
        return len(st)