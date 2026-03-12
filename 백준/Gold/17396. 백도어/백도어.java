import java.io.*;
import java.util.*;

public class Main {

    static class Edge implements Comparable<Edge> {
        int to;
        long weight;
        Edge(int to, long weight) {
            this.to = to;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge o) {
            return Long.compare(this.weight, o.weight);
        }
    }

    static ArrayList<Edge>[] route;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[] vision = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            vision[i] = Integer.parseInt(st.nextToken());
        vision[N - 1] = 0;

        route = new ArrayList[N];
        for (int i = 0; i < N; i++)
            route[i] = new ArrayList<>();

        while (M-- > 0) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());

            if (vision[b] == 0) route[a].add(new Edge(b, t));
            if (vision[a] == 0) route[b].add(new Edge(a, t));
        }

        System.out.println(solve(N));
    }

    static long solve(int N) {
        long[] dist = new long[N];
        Arrays.fill(dist, Long.MAX_VALUE);

        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.offer(new Edge(0, 0));
        dist[0] = 0;

        while (!pq.isEmpty()) {
            Edge cur = pq.poll();
            if (dist[cur.to] < cur.weight) continue;

            for (Edge next : route[cur.to]) {
                if (dist[next.to] > cur.weight + next.weight) {
                    dist[next.to] = cur.weight + next.weight;
                    pq.offer(new Edge(next.to, cur.weight + next.weight));
                }
            }
        }

        if (dist[N - 1] == Long.MAX_VALUE) return -1;
        return dist[N - 1];
    }
}
