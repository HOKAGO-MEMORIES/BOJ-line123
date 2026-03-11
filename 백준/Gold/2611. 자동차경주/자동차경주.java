import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    static class Edge {
        int to, weight;
        Edge(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }
    }

    static int[] degree;
    static ArrayList<Edge>[] adj;
    static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        degree = new int[N + 1];

        adj = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++)
            adj[i] = new ArrayList<>();

        while (M-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int p = Integer.parseInt(st.nextToken());
            int q = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            adj[p].add(new Edge(q, r));
            if (q != 1) degree[q]++;
        }

        System.out.println(solve());
    }

    static String solve() {
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(1);

        int[] dp = new int[N + 1];
        int[] parents = new int[N + 1];

        while (!q.isEmpty()) {
            int cur = q.poll();
            for (Edge edge : adj[cur]) {
                int next = edge.to;
                int weight = edge.weight;

                if (dp[next] < dp[cur] + weight) {
                    dp[next] = dp[cur] + weight;
                    parents[next] = cur;
                }

                if (next != 1) {
                    degree[next]--;
                    if (degree[next] == 0)
                        q.offer(next);
                }
            }
        }

        ArrayDeque<Integer> result = new ArrayDeque<>();
        int cur = 1;
        result.addFirst(1);
        while (parents[cur] != 1) {
            cur = parents[cur];
            result.addFirst(cur);
        }
        result.addFirst(1);


        return String.valueOf(dp[1]) + '\n' +
                result.stream()
                        .map(String::valueOf)
                        .collect(Collectors.joining(" "));
    }
}
