import java.io.*;
import java.util.*;

public class Main {

    static class Node implements Comparable<Node> {
        int end, cost;
        Node(int to, int cost) {
            this.end = to;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node o) {
            return this.cost - o.cost;
        }
    }

    private static int[] dist, route;
    private static ArrayList<ArrayList<Node>> list;
    private final static int INF = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        dist = new int[n + 1];
        route = new int[n + 1];
        list = new ArrayList<>();

        Arrays.fill(dist, INF);
        for (int i = 0; i <= n; i++)
            list.add(new ArrayList<>());

        while (m-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            list.get(start).add(new Node(end, cost));
        }

        StringTokenizer st = new StringTokenizer(br.readLine());
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());

        solve(A);

        ArrayList<Integer> path = new ArrayList<>();
        int cur = B;
        while (cur != 0) {
            path.add(cur);
            cur = route[cur];
        }
        Collections.reverse(path);

        StringBuilder sb = new StringBuilder();
        sb.append(dist[B]).append('\n')
                        .append(path.size()).append('\n');
        for (int node : path)
            sb.append(node).append(" ");

        System.out.println(sb);
    }

    private static void solve(int A) {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(A, 0));
        dist[A] = 0;

        while (!pq.isEmpty()) {
            Node cur = pq.poll();
            if (cur.cost > dist[cur.end]) continue;

            for (Node next : list.get(cur.end)) {
                if (dist[next.end] > dist[cur.end] + next.cost) {
                    dist[next.end] = dist[cur.end] + next.cost;
                    route[next.end] = cur.end;
                    pq.offer(new Node(next.end, dist[next.end]));
                }
            }
        }
    }

}
