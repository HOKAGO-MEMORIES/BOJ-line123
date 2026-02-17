import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static char[][] graph;
    static boolean[][] visitedA, visitedB;
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        graph = new char[N][N];

        for (int i = 0; i < N; i++) {
            String input = br.readLine();
            for (int j = 0; j < N; j++)
                graph[i][j] = input.charAt(j);
        }

        solve();

        System.out.println(sb);
    }

    static void solve() {
        int cntA = 0, cntB = 0;
        visitedA = new boolean[N][N];
        visitedB = new boolean[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visitedA[i][j]) {
                    cntA++;
                    checkArea(i, j, false);
                }

                if (!visitedB[i][j]) {
                    cntB++;
                    checkArea(i, j, true);
                }
            }
        }

        sb.append(cntA).append(" ").append(cntB);
    }

    static void checkArea(int x, int y, boolean isBlindness) {
        char curColor = graph[x][y];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                if (isBlindness) {
                    if (!visitedB[nx][ny] && checkRG(graph[nx][ny], curColor)) {
                        visitedB[nx][ny] = true;
                        checkArea(nx, ny, true);
                    }
                } else {
                    if (!visitedA[nx][ny] && graph[nx][ny] == curColor) {
                        visitedA[nx][ny] = true;
                        checkArea(nx, ny, false);
                    }
                }
            }
        }
    }

    static boolean checkRG(char next, char cur) {
        if (next == 'B')
            return next == cur;
        else
            return cur != 'B';
    }
}
