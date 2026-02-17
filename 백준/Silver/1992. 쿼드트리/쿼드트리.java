import java.io.*;
import java.util.*;

public class Main {

    static int[][] graph;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        graph = new int[N + 1][N + 1];

        for (int i = 1; i <= N; i++) {
            String input = br.readLine();
            for (int j = 1; j <= N; j++)
                graph[i][j] = input.charAt(j - 1) - '0';
        }

        solve(1, 1, N);
        System.out.println(sb);
    }

    static void solve(int x, int y, int N) {
        int firstElement = graph[x][y];
        boolean isSame = true;

        for (int i = x; i < x + N; i++) {
            for (int j = y; j < y + N; j++) {
                if (firstElement != graph[i][j]) {
                    isSame = false;
                    break;
                }
            }

            if (!isSame)
                break;
        }

        callRecursion(x, y, N, isSame);
    }

    static void callRecursion(int x, int y, int N, boolean isSame) {
        if (isSame)
            sb.append(graph[x][y]);
        else {
            sb.append("(");
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    solve(x + (N * i) / 2, y + (N * j) / 2, N / 2);
            sb.append(")");
        }
    }
}
