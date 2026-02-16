import java.io.*;
import java.util.*;

public class Main {

    static ArrayList<Integer>[] friends;
    static boolean[] visited;
    static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        friends = new ArrayList[N];
        visited = new boolean[N];

        for (int i = 0; i < N; i++)
            friends[i] = new ArrayList<>();

        while (M-- > 0) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            friends[a].add(b);
            friends[b].add(a);
        }

        boolean found = false;
        for (int i = 0; i < N; i++) {
            if (solve(i, 0)) {
                found = true;
                break;
            }
        }

        if (found) System.out.println(1);
        else System.out.println(0);
    }

    static boolean solve(int cur, int cnt) {
        if (cnt == 4)
            return true;

        visited[cur] = true;
        for (int next : friends[cur])
            if (!visited[next])
                if (solve(next, cnt + 1))
                    return true;
        visited[cur] = false;

        return false;
    }
}
