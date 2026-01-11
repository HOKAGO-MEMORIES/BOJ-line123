import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int result = 0;
    static int[][] map;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        map = new int[N + 1][N + 1];

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        solve(1, 2, 1);
        System.out.println(result);
    }

    // dir - 1:가로 / 2:세로 / 0:대각선
    static void solve(int x, int y, int dir) {
        if (x == N && y == N) {
            result++;
            return;
        }

        if (dir == 0) {
            checkAndDeploy(x, y + 1, 1);
            checkAndDeploy(x + 1, y, 2);
            checkAndDeploy(x + 1, y + 1, 0);
        } else if (dir == 1) {
            checkAndDeploy(x, y + 1, 1);
            checkAndDeploy(x + 1, y + 1, 0);
        } else if (dir == 2) {
            checkAndDeploy(x + 1, y, 2);
            checkAndDeploy(x + 1, y + 1, 0);
        }
    }

    static void checkAndDeploy(int nx, int ny, int dir) {
        if (nx > N || ny > N) {
            return;
        }

        if (dir == 0) {
            if (map[nx][ny] == 0 && map[nx - 1][ny] == 0 && map[nx][ny - 1] == 0) {
                solve(nx, ny, dir);
            }
        } else {
            if (map[nx][ny] == 0) {
                solve(nx, ny, dir);
            }
        }
    }
}
