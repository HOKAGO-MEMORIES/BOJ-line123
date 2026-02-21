import java.io.*;
import java.util.*;

public class Main {

    static int[][] photo, field;
    static int N, K, ans;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        field = new int[N + 1][N + 1];
        photo = new int[N + 1][N + 1];

        int Q = Integer.parseInt(br.readLine());
        while (Q-- > 0) {
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            sb.append(solve(r, c, v)).append('\n');
        }

        System.out.println(sb);
    }

    static int solve(int r, int c, int v) {
        int diff = v - field[r][c];
        field[r][c] = v;

        for (int i = Math.max(1, r - K + 1); i <= Math.min(N - K + 1, r); i++) {
            for (int j = Math.max(1, c - K + 1); j <= Math.min(N - K + 1, c); j++) {
                photo[i][j] += diff;
                ans = Math.max(ans, photo[i][j]);
            }
        }

        return ans;
    }
}
