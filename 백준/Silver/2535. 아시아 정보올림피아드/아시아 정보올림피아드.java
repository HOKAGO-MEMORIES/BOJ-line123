import java.io.*;
import java.util.*;

public class Main {

    static class Node {
        int country, number, score;
        Node(int country, int number, int score) {
            this.country = country;
            this.number = number;
            this.score = score;
        }
    }

    private static Node[] nodes;
    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int N = Integer.parseInt(br.readLine());
        nodes = new Node[N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            int country = Integer.parseInt(st.nextToken());
            int number = Integer.parseInt(st.nextToken());
            int score = Integer.parseInt(st.nextToken());

            nodes[i] = new Node(country, number, score);
        }

        Arrays.sort(nodes, (n1, n2) -> n2.score - n1.score);
        solve(N);
        System.out.println(sb);
    }

    private static void solve(int N) {
        int cnt = 0;
        int[] count = new int[N];

        for (Node node : nodes) {
            if (cnt == 3) break;
            if (count[node.country] == 2) continue;

            sb.append(node.country).append(" ").append(node.number).append('\n');
            cnt++;
            count[node.country]++;
        }
    }
}
