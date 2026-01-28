import java.io.*;
import java.util.*;

public class Main {

    private static class Node {
        int x, y;

        private Node (int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private static int N, M, ans, originSafeZone;
    private static int[][] originMap;
    private static int[] dx = {1, 0, -1, 0};
    private static int[] dy = {0, 1, 0, -1};
    private static Queue<Node> originVirus;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        originMap = new int[N][M];
        originVirus = new ArrayDeque<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                int num = Integer.parseInt(st.nextToken());
                originMap[i][j] = num;
                if (num == 2)
                    originVirus.add(new Node(i, j));
                if (num == 0)
                    originSafeZone++;
            }
        }

        buildWall(0, 0);
        System.out.println(ans);
    }

    private static void buildWall(int cnt, int start) {
        if (cnt == 3) {
            bfs();
            return;
        }

        // 순열에서 조합 방식으로 변경 (순서만 다르고 똑같은 경우 제거)
        for (int i = start; i < N * M; i++) {
            int r = i / M;
            int c = i % M;

            if (originMap[r][c] == 0) {
                originMap[r][c] = 1;
                buildWall(cnt + 1, i + 1);
                originMap[r][c] = 0;
            }

        }
    }

    private static void bfs() {
        Queue<Node> virus = new ArrayDeque<>();
        for (Node node : originVirus)
            virus.add(new Node(node.x, node.y));

        int[][] map = new int[N][M];
        for (int i = 0; i < N; i++)
            map[i] = originMap[i].clone();

        int safeZone = originSafeZone - 3;

        while(!virus.isEmpty()) {
            Node v = virus.poll();
            int x = v.x;
            int y = v.y;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                    if (map[nx][ny] == 0) {
                        map[nx][ny] = 2;
                        safeZone--;
                        virus.add(new Node(nx, ny));
                    }
                }
            }
        }

        ans = Math.max(ans, safeZone);
    }

}
