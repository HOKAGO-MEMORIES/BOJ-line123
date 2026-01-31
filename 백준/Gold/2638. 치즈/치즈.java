import java.util.*;
import java.io.*;

public class Main {

    static class Node {
        int x, y;
        Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private static int N, M;
    private static int[] dx = {1, 0, -1, 0};
    private static int[] dy = {0, 1, 0, -1};
    private static int[][] graph;
    private static Queue<Node> cheese;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        graph = new int[N][M];
        cheese = new ArrayDeque<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                graph[i][j] = Integer.parseInt(st.nextToken());
                if (graph[i][j] == 1) cheese.offer(new Node(i, j));
            }
        }

        System.out.println(solve());
    }

    private static int solve() {
        int time = 0;

        while (!cheese.isEmpty()) {
            boolean[][] outerAir = new boolean[N][M];
            checkAir(outerAir);
            meltCheese(outerAir);
            time++;
        }

        return time;
    }

    private static void checkAir(boolean[][] outerAir) {
        Queue<Node> air = new ArrayDeque<>();
        air.add(new Node(0, 0));

        while (!air.isEmpty()) {
            Node a = air.poll();
            int x = a.x;
            int y = a.y;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                    if (graph[nx][ny] != 1 && !outerAir[nx][ny]) {
                        outerAir[nx][ny] = true;
                        air.offer(new Node(nx, ny));
                    }
                }

            }
        }
    }

    private static void meltCheese(boolean[][] outerAir) {
        int len = cheese.size();
        while (len-- > 0) {
            Node c = cheese.poll();
            int x = c.x;
            int y = c.y;
            int check = 0;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < N && ny < M)
                    if (outerAir[nx][ny])
                        check++;
            }

            if (check < 2)
                cheese.offer(c);
            else
                graph[x][y] = 0;
        }
    }
}
