import java.io.*;
import java.util.*;

public class Main {

    private static char[][] map;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        map = new char[N][N * 2];

        for (int i = 0; i < N; i++) {
            Arrays.fill(map[i], ' ');
        }

        solve(0, N - 1, N);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N * 2; j++) {
                sb.append(map[i][j]);
            }
            sb.append('\n');
        }

        System.out.println(sb);
    }

    private static void solve(int r, int c, int size) {
        if (size == 3) {
            map[r][c] = '*';
            map[r + 1][c - 1] = map[r + 1][c + 1] = '*';
            map[r + 2][c - 2] = map[r + 2][c - 1] = map[r + 2][c] = map[r + 2][c + 1] = map[r + 2][c + 2] = '*';
            return;
        }

        size /= 2;
        solve(r, c, size);
        solve(r + size, c - size, size);
        solve(r + size, c + size, size);
    }
}
