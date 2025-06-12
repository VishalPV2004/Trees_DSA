class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int i = 0 ; i < inorder.length ; i++)
        {
            map.put(inorder[i],i);
        }

        TreeNode root = getBuild(postorder,0,postorder.length-1,inorder,0,inorder.length-1,map);

        return root;
    }

    public TreeNode getBuild(int[] postorder, int ps, int pe, int[] inorder, int is, int ie, HashMap<Integer,Integer> map)
    {
        if (ps > pe || is > ie)
           return null;
        
        TreeNode root = new TreeNode(postorder[pe]);
        int inroot = map.get(root.val);
        int numsleft = inroot - is;

        root.left = getBuild(postorder,ps,ps+numsleft-1,inorder,is,inroot-1,map);
        root.right = getBuild(postorder,ps+numsleft,pe-1,inorder,inroot+1,ie,map);

        return root;
    }
}