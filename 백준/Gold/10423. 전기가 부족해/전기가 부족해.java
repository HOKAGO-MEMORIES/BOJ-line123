import java.io.*;
import java.util.*;

public class Main {

    static class Edge implements Comparable<Edge> {
        int u, v, w;
        Edge (int u, int v, int w) {
            this.u = u;
            this.v = v;
            this.w = w;
        }

        @Override
        public int compareTo(Edge o) {
            return this.w - o.w;
        }
    }

    static int[] parents;
    static boolean[] isPlant;
    static List<Edge> edgeList = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        parents = new int[N + 1];
        isPlant = new boolean[N + 1];

        for (int i = 1; i <= N; i++)
            parents[i] = i;

        st = new StringTokenizer(br.readLine());
        while (K-- > 0) {
            int plant = Integer.parseInt(st.nextToken());
            isPlant[plant] = true;
        }

        while (M-- > 0) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            edgeList.add(new Edge(u, v, w));
        }

        Collections.sort(edgeList);

        System.out.println(solve());
    }

    static int solve() {
        int ans = 0;

        for (Edge edge : edgeList) {
            int u = find(edge.u);
            int v = find(edge.v);

            if (u == v) continue;
            if (isPlant[u] && isPlant[v]) continue;

            union(u, v);
            ans += edge.w;
        }

        return ans;
    }

    static void union(int u, int v) {
        u = find(u);
        v = find(v);

        if (isPlant[u]) parents[v] = u;
        else if (isPlant[v]) parents[u] = v;
        else parents[u] = v;
    }

    static int find(int x) {
        if (parents[x] == x) return x;
        return parents[x] = find(parents[x]);
    }
}
