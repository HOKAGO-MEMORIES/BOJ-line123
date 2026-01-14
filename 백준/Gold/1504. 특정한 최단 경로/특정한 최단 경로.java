import java.util.*;
import java.io.*;

public class Main {

    private static class Node implements Comparable<Node> {
        int end, cost;

        public Node(int end, int cost) {
            this.end = end;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node n) {
            return this.cost - n.cost;
        }
    }

    private static int N, E, INF = 200000000;
    private static ArrayList<Node>[] list;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        list = new ArrayList[N + 1];
        for (int i = 0; i <= N; i++) {
            list[i] = new ArrayList<>();
        }

        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            list[a].add(new Node(b, c));
            list[b].add(new Node(a, c));
        }

        st = new StringTokenizer(br.readLine());
        int v1 = Integer.parseInt(st.nextToken());
        int v2 = Integer.parseInt(st.nextToken());

        int result = solve(v1, v2);
        System.out.println(result);
    }

    private static int solve(int v1, int v2) {
        int result1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N);
        int result2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N);

        if (result1 >= INF && result2 >= INF)
            return -1;

        return Math.min(result1, result2);
    }

    private static int dijkstra(int start, int end) {
        int[] dist = new int[N + 1];
        PriorityQueue<Node> pq = new PriorityQueue<>();

        Arrays.fill(dist, INF);
        dist[start] = 0;
        pq.add(new Node(start, 0));

        while (!pq.isEmpty()) {
            Node cur = pq.poll();

            if (dist[cur.end] < cur.cost) continue;

            for (Node next : list[cur.end]) {
                if (dist[next.end] > dist[cur.end] + next.cost) {
                    dist[next.end] = dist[cur.end] + next.cost;
                    pq.add(new Node(next.end, dist[next.end]));
                }
            }
        }

        return dist[end];
    }
}
