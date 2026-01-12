import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static int[] parent;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        parent = new int[N + 1];
        for (int i = 0; i <= N; i++) {
            parent[i] = i;
        }

        st = new StringTokenizer(br.readLine());
        int trueCount = Integer.parseInt(st.nextToken());
        // 진실 알면 모두 0(최상위)으로
        for (int i = 0; i < trueCount; i++) {
            int truePerson = Integer.parseInt(st.nextToken());
            union(0, truePerson);
        }

        int ans = solve();
        System.out.println(ans);
    }

    public static int solve() throws IOException {
        StringTokenizer st;
        ArrayList<Integer>[] parties = new ArrayList[M];

        for (int i = 0; i < M; i++) {
            parties[i] = new ArrayList<>();
            st = new StringTokenizer(br.readLine());
            int partySize = Integer.parseInt(st.nextToken());

            int firstPerson = Integer.parseInt(st.nextToken());
            parties[i].add(firstPerson);

            // 파티원끼리 묶기
            for (int j = 1; j < partySize; j++) {
                int nextPerson = Integer.parseInt(st.nextToken());
                parties[i].add(nextPerson);
                union(firstPerson, nextPerson);
            }
        }

        int ans = 0;
        for (int i = 0; i < M; i++) {
            int partyLeader = parties[i].get(0);
            // 0이 아니면 거짓말 가능
            if (find(partyLeader) != find(0)) {
                ans++;
            }
        }

        return ans;
    }

    public static int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    public static void union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (a < b) parent[b] = a;
            else parent[a] = b;
        }
    }
}
