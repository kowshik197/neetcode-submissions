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
    
    public int count=0;
    public void dfs(TreeNode head,int maxi){
        if(head==null){
            return;
        }
        int temp=head.val;

        if(temp>=maxi){
            count++;
            maxi=temp;
        }
        
        dfs(head.left,maxi);
        dfs(head.right,maxi);

    }
    public int goodNodes(TreeNode root) {
        count = 0;
        dfs(root,Integer.MIN_VALUE);
        return count;
    }
}
