import java.io.*;
import java.util.*;

public class Main {

    private static class Node {
        Node left, right;
        int val;

        private Node(int val) {
            this.val = val;
        }

        private void insert(int val) {
            if (val > this.val) {
                if (this.right == null) {
                    this.right = new Node(val);
                } else {
                    this.right.insert(val);
                }
            } else {
                if (this.left == null) {
                    this.left = new Node(val);
                } else {
                    this.left.insert(val);
                }
            }
        }
    }

    private static final StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Node root = new Node(Integer.parseInt(br.readLine()));
        String input;

        while (true) {
            input = br.readLine();
            if (input == null || input.isBlank()) {
                break;
            }

            root.insert(Integer.parseInt(input));
        }

        postOrder(root);
        System.out.println(sb);
    }

    private static void postOrder(Node node) {
        if (node == null) return;
        postOrder(node.left);
        postOrder(node.right);
        sb.append(node.val).append('\n');
    }
}
