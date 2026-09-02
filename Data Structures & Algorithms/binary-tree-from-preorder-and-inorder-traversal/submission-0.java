/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {

    int preIndex = 0;

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return build(preorder, inorder, 0, inorder.length - 1);
    }

    private TreeNode build(int[] preorder, int[] inorder, int left, int right) {

        if (left > right)
            return null;

        // Preorder gives the root
        int rootValue = preorder[preIndex++];
        TreeNode root = new TreeNode(rootValue);

        // Find root in inorder
        int index = left;
        while (inorder[index] != rootValue)
            index++;

        // Build left subtree
        root.left = build(preorder, inorder, left, index - 1);

        // Build right subtree
        root.right = build(preorder, inorder, index + 1, right);

        return root;
    }
}