import java.io.*;
import java.util.*;

public class Main {

    static class Edge implements Comparable<Edge> {
        int u, v, weight;
        public Edge(int u, int v, int weight) {
            this.u = u;
            this.v = v;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge o) {
            return Integer.compare(this.weight, o.weight);
        }
    }

    static int[] parent;
    static ArrayList<Edge> edgeList;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int V = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());

        edgeList = new ArrayList<>();
        parent = new int[V + 1];
        for (int i = 1; i <= V; i++)
            parent[i] = i;

        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());
            edgeList.add(new Edge(A, B, C));
        }

        Collections.sort(edgeList);
        System.out.println(solve());
    }

    static int solve() {
        int ans = 0;
        for (Edge edge : edgeList)
            if (union(edge.u, edge.v))
                ans += edge.weight;

        return ans;
    }

    static boolean union(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return false;

        parent[v] = u;
        return true;
    }

    static int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
}
