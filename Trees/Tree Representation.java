import java.util.*;

class Node
{
    int data;
    Node left, right;
    
    Node(int val)
    {
        data = val;
        left = null;
        right = null;
    }

}

class Main
{
    public static void main(String args[])
    {
        Node root = new Node(0);
        root.left = new Node(1);
        root.right = new Node(2);
    }
}