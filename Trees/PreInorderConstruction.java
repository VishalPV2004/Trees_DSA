class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int i = 0 ; i < inorder.length ; i++)
        {
            map.put(inorder[i],i);
        }

        TreeNode root = getBuild(preorder,0,preorder.length-1,inorder,0,inorder.length-1,map);

        return root;
    }

    public TreeNode getBuild(int[] preorder, int ps, int pe, int[] inorder, int is, int ie,HashMap<Integer,Integer> map)
    {
        if (ps > pe || is > ie)
           return null;
        
        TreeNode root = new TreeNode(preorder[ps]);
        int inroot = map.get(root.val);
        int numsleft = inroot-is;
        root.left = getBuild(preorder,ps+1,ps+numsleft,inorder,is,inroot-1,map);
        root.right = getBuild(preorder,ps+numsleft+1,pe,inorder,inroot+1,ie,map);

        return root;
    }
}