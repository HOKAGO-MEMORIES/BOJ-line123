import java.util.*;
import java.io.*;

public class Main {

    static class Node implements Comparable<Node> {
        int end, weight;
        public Node(int end, int weight) {
            this.end = end;
            this.weight = weight;
        }

        @Override
        public int compareTo(Node o) {
            return Integer.compare(this.weight, o.weight);
        }
    }

    static ArrayList<Node>[] graph;
    static int[] parent;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        parent = new int[N + 1];
        graph = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++)
            graph[i] = new ArrayList<>();

        while (M-- > 0) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());

            graph[a].add(new Node(b, t));
            graph[b].add(new Node(a, t));
        }

        for (int i = 1; i <= N; i++)
            Collections.sort(graph[i]);

        int originalMinTIme = solve(N, -1, -1);
        int curNode = N;
        int maxDelay = 0;

        while (curNode != 1) {
            int prevNode = parent[curNode];
            int blockedTime = solve(N, prevNode, curNode);

            if (blockedTime == Integer.MAX_VALUE) {
                System.out.println(-1);
                return;
            }

            maxDelay = Math.max(maxDelay, blockedTime - originalMinTIme);
            curNode = prevNode;
        }

        System.out.println(maxDelay);
    }

    static int solve(int N, int blockA, int blockB) {
        int[] dist = new int[N + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[1] = 0;

        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(1, 0));

        while (!pq.isEmpty()) {
            Node cur = pq.poll();

            if (dist[cur.end] < cur.weight) continue;

            for (Node next : graph[cur.end]) {
                if ((cur.end == blockA && next.end == blockB) ||
                    (cur.end == blockB && next.end == blockA))
                    continue;

                if (dist[next.end] > dist[cur.end] + next.weight) {
                    dist[next.end] = dist[cur.end] + next.weight;
                    pq.offer(new Node(next.end, dist[next.end]));

                    if (blockA == -1)
                        parent[next.end] = cur.end;
                }
            }
        }

        return dist[N];
    }
}
